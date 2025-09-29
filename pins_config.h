#pragma once

/***********************config*************************/

#define SPI_FREQUENCY         10000000 //
#define TFT_SPI_MODE          SPI_MODE0
#define TFT_SPI_HOST          SPI2_HOST

#define EXAMPLE_LCD_H_RES     466 // sls project horizontal resolution
#define EXAMPLE_LCD_V_RES     466 // sls project vertical resolution
#define LVGL_LCD_BUF_SIZE     (EXAMPLE_LCD_H_RES * EXAMPLE_LCD_V_RES)

#define LCD_WIDTH             466 //physical display horizontal resolution
#define LCD_HEIGHT            466 //physical display vertical resolution
#define SEND_BUF_SIZE         (0x4000)//(LCD_WIDTH * LCD_HEIGHT + 8) / 10

// LILYGO AMOLED 1.75 - 1.75 inches
#if defined(LILYGO_AMOLED_1_75)
#define TFT_QSPI_CS           10
#define TFT_QSPI_SCK          12
#define TFT_QSPI_D0           11
#define TFT_QSPI_D1           13
#define TFT_QSPI_D2           14
#define TFT_QSPI_D3           15
#define TFT_QSPI_RST          17
#define LCD_EN                16
#define TFT_TE                -1

// IIC
#define IIC_SDA 7
#define IIC_SCL 6

// TOUCH
#define TOUCH_INT 9
#define TOUCH_RST 8

// Battery Voltage ADC
#define BATTERY_VOLTAGE_ADC_DATA 4

// SD
#define SD_CS 38
#define SD_MOSI 39
#define SD_MISO 40
#define SD_SCLK 41

// PCF8563
#define PCF8563_INT 9
#endif //LILYGO

#if defined(WAVESHARE_AMOLED_1_75)
// WAVESHARE H0175Y003AM - 1.75 inches
#define XPOWERS_CHIP_AXP2101

#define TFT_QSPI_CS           12
#define TFT_QSPI_SCK          38
#define TFT_QSPI_D0           4
#define TFT_QSPI_D1           5
#define TFT_QSPI_D2           6
#define TFT_QSPI_D3           7
#define TFT_QSPI_RST          39
#define LCD_VCI_EN            13
#define TFT_TE                -1

// IIC
#define IIC_SDA 15
#define IIC_SCL 14

// TOUCH
#define TOUCH_INT 11
#define TOUCH_RST 40

// ES8311
#define I2S_MCK_IO 16
#define I2S_BCK_IO 9
#define I2S_DI_IO 10
#define I2S_WS_IO 45
#define I2S_DO_IO 8


#define MCLKPIN             42
#define BCLKPIN              9
#define WSPIN               45
#define DOPIN               10
#define DIPIN                8
#define PA                  46

// SD
#define SD_CS 41
#define SD_MOSI 1
#define SD_MISO 3
#define SD_SCLK 2

const int SDMMC_CLK = 2;
const int SDMMC_CMD = 1;
const int SDMMC_DATA = 3;
const int SDMMC_CS = 41;




// Battery Voltage ADC
#define BATTERY_VOLTAGE_ADC_DATA 4


// PCF8563
#define PCF8563_INT 9


//   i2s.setPins(BCLKPIN, WSPIN, DIPIN, DOPIN, MCLKPIN);
#define MCLKPIN             42
#define BCLKPIN              9
#define WSPIN               45
#define DOPIN                8
#define DIPIN               10
#define PAPIN               46

// BOOT button is tied to GPIO_NUM_0 pin
#define BOOT_BUTTON            GPIO_NUM_0

// IO Expander
#define PWR_BUTTON  4   // PWR button via EXI04?
#define AXP_IRQ     5   // AXP2101 interrupt is tied to EXIO5
#endif //WAVESHARE H0175Y003AM

#define SLEEP_WAKE_UP_INT GPIO_NUM_0