/*
 * Luna TV remote controller keytable
 *
 * Copyright (C) 2010 Antti Palosaari <crope@iki.fi>
 *
 *    This program is free software; you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation; either version 2 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License along
 *    with this program; if not, write to the Free Software Foundation, Inc.,
 *    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <media/rc-map.h>
#include <linux/module.h>

#define RC_MAP_NEC_LUNA_TV "rc-nec-lunatv"

static struct rc_map_table nec_lunatv_ks[] = {
	{ 0x118, KEY_POWER2 }, /* Power */
	{ 0x146, KEY_UP }, /* Up */
	{ 0x116, KEY_DOWN }, /* Down */
	{ 0x147, KEY_LEFT }, /* Left */
	{ 0x115, KEY_RIGHT }, /* Right */
	{ 0x155, KEY_ENTER }, /* Enter */
	{ 0x117, KEY_MENU }, /* Menu */
	{ 0x106, KEY_HOME }, /* Home */
	{ 0x114, KEY_VOLUMEDOWN }, /* Vol- */
	{ 0x110, KEY_VOLUMEUP }, /* Vol+ */
	{ 0x140, KEY_ESC }, /* Esc */

	{ 0x102d1f, KEY_POWER2 }, /* Power */
	{ 0x102d09, KEY_PAGEUP }, /* Channel+ */
	{ 0x102d12, KEY_PAGEDOWN }, /* Channel- */
	{ 0x102d10, KEY_VOLUMEUP }, /* Volume+ */
	{ 0x102d11, KEY_VOLUMEDOWN }, /* Volume- */
	{ 0x102d43, KEY_MUTE }, /* Mute */
	{ 0x102d5c, KEY_1 }, /* 1 */
	{ 0x102d1e, KEY_2 }, /* 2 */
	{ 0x102d5e, KEY_3 }, /* 3 */
	{ 0x102d58, KEY_4 }, /* 4 */
	{ 0x102d1a, KEY_5 }, /* 5 */
	{ 0x102d5b, KEY_6 }, /* 6 */
	{ 0x102d1b, KEY_7 }, /* 7 */
	{ 0x102d59, KEY_8 }, /* 8 */
	{ 0x102d5a, KEY_9 }, /* 9 */
	{ 0x102d19, KEY_0 }, /* 0 */
	{ 0x102d4a, KEY_UP }, /* Up */
	{ 0x102d4b, KEY_DOWN }, /* Down */
	{ 0x102d0b, KEY_LEFT }, /* Left */
	{ 0x102d08, KEY_RIGHT }, /* Right */
	{ 0x102d49, KEY_ENTER }, /* Enter */
	{ 0x102d07, KEY_MENU }, /* Menu */
	{ 0x102d5f, KEY_ESC }, /* Esc */
};

static struct rc_map_list nec_lunatv_ks_map = {
	.map = {
		.scan    = nec_lunatv_ks,
		.size    = ARRAY_SIZE(nec_lunatv_ks),
		.rc_proto = RC_PROTO_NEC,
		.name    = RC_MAP_NEC_LUNA_TV,
	}
};

static int __init init_rc_map_nec_lunatv_ks(void)
{
	return rc_map_register(&nec_lunatv_ks_map);
}

static void __exit exit_rc_map_nec_lunatv_ks(void)
{
	rc_map_unregister(&nec_lunatv_ks_map);
}

module_init(init_rc_map_nec_lunatv_ks)
module_exit(exit_rc_map_nec_lunatv_ks)

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kyosuke Nekoyashiki <supercatexpert@gmail.com>");
