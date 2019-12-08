/*
 * config.h
 * 
 * User configuration.
 * 
 * Written & released by Keir Fraser <keir.xen@gmail.com>
 * 
 * This is free and unencumbered software released into the public domain.
 * See the file COPYING for more details, or visit <http://unlicense.org>.
 */

enum dispen { DISPCTL_tristate = 0, DISPCTL_enable_high, DISPCTL_enable_low, DISPCTL_MAX };
/* PB15 is tristate outside OSD; PA15 unused
 * PA15 is Display Enable: Active HIGH
 * PA15 is Display Enable: Active LOW */

extern struct __packed config {

    uint16_t polarity;

    uint16_t h_off, v_off;

    uint16_t min_cols, max_cols;

    uint16_t rows;

#define DISP_15KHZ 0
#define DISP_VGA 1
    uint16_t display_timing;

    uint16_t display_autosync;

#define DISP_SPI2 0
#define DISP_SPI1 1
    uint16_t display_spi;

    /* dispen enum
     * DISPCTL_tristate    0    PB15 is tristate outside OSD; PA15 unused
     * DISPCTL_enable_high 1    PA15 is Display Enable: Active HIGH
     * DISPCTL_enable_low  2    PA15 is Display Enable: Active LOW */
    uint16_t dispctl_mode;

    uint16_t display_2Y;

    /* Mask of user-assigned pins configured in open-drain mode. */
    uint8_t user_pin_opendrain;
    /* Mask of user-assigned pins configured in push-pull mode. */
    uint8_t user_pin_pushpull;
    /* Mask of user-assigned pins which are HIGH at power on. */
    uint8_t user_pin_high;
    uint8_t _pad;
    struct __packed config_hotkey {
        /* Mask of user pins modified by this hotkey. */
        uint8_t pin_mod;
        /* Mask of user pins driven HIGH by this hotkey. 
         * Pins in @pin_mod but not in @pin_high are driven LOW. */
        uint8_t pin_high;
        char str[30];
    } hotkey[10];

    uint16_t crc16_ccitt;

} config;

extern bool_t config_active;
extern struct display config_display;

void config_init(void);
void config_process(uint8_t b);

/*
 * Local variables:
 * mode: C
 * c-file-style: "Linux"
 * c-basic-offset: 4
 * tab-width: 4
 * indent-tabs-mode: nil
 * End:
 */
