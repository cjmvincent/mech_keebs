/* Copyright 2024 ProtieusKeebs
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include_next <mcuconf.h>

/* OLED */

//#ifdef OLED_ENABLE
//#    undef RP_I2C_USE_I2C0
//#    define RP_I2C_USE_I2C0 FALSE
//#    undef RP_I2C_USE_I2C1
//#    define RP_I2C_USE_I2C1 TRUE
//#    define I2C_DRIVER I2CD2
//#    define I2C1_SDA_PIN GP6
//#    define I2C1_SCL_PIN GP7
//#endif


/* Trackball */

//#ifdef POINTING_DEVICE_ENABLE
//#    undef RP_SPI_USE_SPI0
//#    define RP_SPI_USE_SPI0 FALSE
#    undef RP_SPI_USE_SPI1
#    define RP_SPI_USE_SPI1 TRUE
//#    define RP_SPI_USE_SPI0 TRUE
//#    define SPI_DRIVER SPID0
//#    define SPI_SCK_PIN GP18
//#    define SPI_MISO_PIN GP16
//#    define SPI_MOSI_PIN GP19
//#endif
