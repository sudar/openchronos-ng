/*
    rtca.h: TI CC430 Hardware Realtime Clock (RTC_A)

    Copyright (C) 2011-2012 Angelo Arrifano <miknix@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __RTCA_H__
#define __RTCA_H__

#include "project.h"

typedef enum {
	RTCA_EV_ALARM,
	RTCA_EV_MINUTE,
	RTCA_EV_HOUR,
	RTCA_EV_DAY,
	RTCA_EV_MONTH,
	RTCA_EV_YEAR
} rtca_tevent_ev_t;

/* the ev variable holds the time event, see rtca_tevent_ev_t for more info.
please add -fshort-enums to CFLAGS to store rtca_tevent_ev_t as only a byte */
typedef void (*rtca_tevent_fn_t)(rtca_tevent_ev_t ev);

/* list of time event callback functions */
typedef struct rtca_cblist {
	rtca_tevent_fn_t fn;
	struct rtca_cblist *next;
} rtca_cblist_t;

void rtca_init(void);
void rtca_tevent_fn_register(rtca_tevent_fn_t fn);
void rtca_tevent_fn_unregister(rtca_tevent_fn_t fn);

uint8_t rtca_get_max_days(uint8_t month, uint16_t year);
uint32_t rtca_get_systime(void);

void rtca_get_time(uint8_t *hour, uint8_t *min, uint8_t *sec);
void rtca_set_time(uint8_t hour, uint8_t min, uint8_t sec);

void rtca_get_date(uint16_t *year, uint8_t *mon, uint8_t *day, uint8_t *dow);
void rtca_set_date(uint16_t year, uint8_t mon, uint8_t day);

void rtca_get_alarm(uint8_t *hour, uint8_t *min);
void rtca_set_alarm(uint8_t hour, uint8_t min);

void rtca_enable_alarm();
void rtca_disable_alarm();

#endif /* __RTCA_H__ */