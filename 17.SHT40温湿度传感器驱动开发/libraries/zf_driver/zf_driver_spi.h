/*********************************************************************************************************************
 * CH32V307VCT6 Opensourec Library ����CH32V307VCT6 ��Դ�⣩��һ�����ڹٷ� SDK �ӿڵĵ�������Դ��
 * Copyright (c) 2022 SEEKFREE ��ɿƼ�
 *
 * ���ļ���CH32V307VCT6 ��Դ���һ����
 *
 * CH32V307VCT6 ��Դ�� ��������
 * �����Ը��������������ᷢ���� GPL��GNU General Public License���� GNUͨ�ù������֤��������
 * �� GPL �ĵ�3�棨�� GPL3.0������ѡ��ģ��κκ����İ汾�����·�����/���޸���
 *
 * ����Դ��ķ�����ϣ�����ܷ������ã�����δ�������κεı�֤
 * ����û�������������Ի��ʺ��ض���;�ı�֤
 * ����ϸ����μ� GPL
 *
 * ��Ӧ�����յ�����Դ���ͬʱ�յ�һ�� GPL �ĸ���
 * ���û�У������<https://www.gnu.org/licenses/>
 *
 * ����ע����
 * ����Դ��ʹ�� GPL3.0 ��Դ���֤Э�� �����������Ϊ���İ汾
 * �������Ӣ�İ��� libraries/doc �ļ����µ� GPL3_permission_statement.txt �ļ���
 * ���֤������ libraries �ļ����� �����ļ����µ� LICENSE �ļ�
 * ��ӭ��λʹ�ò����������� ���޸�����ʱ���뱣����ɿƼ��İ�Ȩ����������������
 *
 * �ļ�����          zf_driver_spi
 * ��˾����          �ɶ���ɿƼ����޹�˾
 * �汾��Ϣ          �鿴 libraries/doc �ļ����� version �ļ� �汾˵��
 * ��������          MounRiver Studio V1.8.1
 * ����ƽ̨          CH32V307VCT6
 * ��������          https://seekfree.taobao.com/
 *
 * �޸ļ�¼
 * ����                                      ����                             ��ע
 * 2022-09-15        ��W            first version
 ********************************************************************************************************************/

#ifndef _zf_driver_spi_h
#define _zf_driver_spi_h

#include "ch32v30x_spi.h"
#include "ch32v30x_rcc.h"
#include "ch32v30x_gpio.h"

#include "zf_common_debug.h"
#include "zf_common_clock.h"

#include "zf_driver_gpio.h"

// ����SPIͨ���ٶ�����ģʽ
#define SPI_SPEED_PRIORITY

// SPIģ��ѡ��ö��
typedef enum
{
    SPI_1 = 0x00, // SPI1ģ��
    SPI_2 = 0x01, // SPI2ģ��
    SPI_3 = 0x02  // SPI3ģ��
} spi_index_enum;

// SPI����ӳ��ö��
typedef enum
{
    //----------SPI1----------
    // SPI1Ĭ��ӳ��������
    SPI1_MAP0_SCK_A5 = 0x0000 | A5,  // SPI1ʱ�����ţ�Ĭ��ӳ�䵽A5
    SPI1_MAP0_MISO_A6 = 0x0000 | A6, // SPI1�����������ţ�Ĭ��ӳ�䵽A6
    SPI1_MAP0_MOSI_A7 = 0x0000 | A7, // SPI1����������ţ�Ĭ��ӳ�䵽A7

    // SPI1��ӳ��������
    SPI1_MAP1_SCK_B3 = 0x0100 | B3,  // SPI1ʱ�����ţ���ӳ�䵽B3
    SPI1_MAP1_MISO_B4 = 0x0100 | B4, // SPI1�����������ţ���ӳ�䵽B4
    SPI1_MAP1_MOSI_B5 = 0x0100 | B5, // SPI1����������ţ���ӳ�䵽B5

    //----------SPI2----------
    // SPI2Ĭ��ӳ��������
    SPI2_MAP0_SCK_B13 = 0x1000 | B13,  // SPI2ʱ�����ţ�Ĭ��ӳ�䵽B13
    SPI2_MAP0_MISO_B14 = 0x1000 | B14, // SPI2�����������ţ�Ĭ��ӳ�䵽B14
    SPI2_MAP0_MOSI_B15 = 0x1000 | B15, // SPI2����������ţ�Ĭ��ӳ�䵽B15

    //----------SPI3----------
    // SPI3Ĭ��ӳ��������
    SPI3_MAP0_SCK_B3 = 0x2000 | B3,  // SPI3ʱ�����ţ�Ĭ��ӳ�䵽B3
    SPI3_MAP0_MISO_B4 = 0x2000 | B4, // SPI3�����������ţ�Ĭ��ӳ�䵽B4
    SPI3_MAP0_MOSI_B5 = 0x2000 | B5, // SPI3����������ţ�Ĭ��ӳ�䵽B5

    // SPI3��ӳ��������
    SPI3_MAP1_SCK_C10 = 0x2100 | C10,  // SPI3ʱ�����ţ���ӳ�䵽C10
    SPI3_MAP1_MISO_C11 = 0x2100 | C11, // SPI3�����������ţ���ӳ�䵽C11
    SPI3_MAP1_MOSI_C12 = 0x2100 | C12, // SPI3����������ţ���ӳ�䵽C12

    SPI_MISO_NULL = 0xFFFE, // ��ʹ��MISO����ʱ�Ķ���
    SPI_CS_NULL = 0xFF,     // ��ʹ��CS����ʱ�Ķ���
} spi_pin_enum;

// SPI����ģʽö��
typedef enum
{
    SPI_MODE0, // CPOL=0, CPHA=0
    SPI_MODE1, // CPOL=0, CPHA=1
    SPI_MODE2, // CPOL=1, CPHA=0
    SPI_MODE3, // CPOL=1, CPHA=1
} spi_mode_enum;

// 8λ����д�뺯��
void spi_write_8bit(spi_index_enum spi_n, const uint8 data);
// 8λ��������д�뺯��
void spi_write_8bit_array(spi_index_enum spi_n, const uint8 *data, uint32 len);

// 16λ����д�뺯��
void spi_write_16bit(spi_index_enum spi_n, const uint16 data);
// 16λ��������д�뺯��
void spi_write_16bit_array(spi_index_enum spi_n, const uint16 *data, uint32 len);

// 8λ�Ĵ���д�뺯��
void spi_write_8bit_register(spi_index_enum spi_n, const uint8 register_name, const uint8 data);
// 8λ�Ĵ�������д�뺯��
void spi_write_8bit_registers(spi_index_enum spi_n, const uint8 register_name, const uint8 *data, uint32 len);

// 16λ�Ĵ���д�뺯��
void spi_write_16bit_register(spi_index_enum spi_n, const uint16 register_name, const uint16 data);
// 16λ�Ĵ�������д�뺯��
void spi_write_16bit_registers(spi_index_enum spi_n, const uint16 register_name, const uint16 *data, uint32 len);

// 8λ���ݶ�ȡ����
uint8 spi_read_8bit(spi_index_enum spi_n);
// 8λ���������ȡ����
void spi_read_8bit_array(spi_index_enum spi_n, uint8 *data, uint32 len);

// 16λ���ݶ�ȡ����
uint16 spi_read_16bit(spi_index_enum spi_n);
// 16λ���������ȡ����
void spi_read_16bit_array(spi_index_enum spi_n, uint16 *data, uint32 len);

// 8λ�Ĵ�����ȡ����
uint8 spi_read_8bit_register(spi_index_enum spi_n, const uint8 register_name);
// 8λ�Ĵ��������ȡ����
void spi_read_8bit_registers(spi_index_enum spi_n, const uint8 register_name, uint8 *data, uint32 len);

// 16λ�Ĵ�����ȡ����
uint16 spi_read_16bit_register(spi_index_enum spi_n, const uint16 register_name);
// 16λ�Ĵ��������ȡ����
void spi_read_16bit_registers(spi_index_enum spi_n, const uint16 register_name, uint16 *data, uint32 len);

// 8λ�����շ�����
void spi_transfer_8bit(spi_index_enum spi_n, const uint8 *write_buffer, uint8 *read_buffer, uint32 len);
// 16λ�����շ�����
void spi_transfer_16bit(spi_index_enum spi_n, const uint16 *write_buffer, uint16 *read_buffer, uint32 len);

// SPI��ʼ������
// ����˵����
// spi_n: SPIģ��ѡ��SPI_1/SPI_2/SPI_3��
// mode: SPI����ģʽ��SPI_MODE0/SPI_MODE1/SPI_MODE2/SPI_MODE3��
// baud: SPIͨ�Ų�����
// sck_pin: ʱ������ѡ��
// mosi_pin: �����������ѡ��
// miso_pin: ������������ѡ��
// cs_pin: Ƭѡ����ѡ��
void spi_init(spi_index_enum spi_n, spi_mode_enum mode, uint32 baud, spi_pin_enum sck_pin, spi_pin_enum mosi_pin, spi_pin_enum miso_pin, gpio_pin_enum cs_pin);

#endif
