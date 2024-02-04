#include "port_addresses.h"

/* E, J, P, K */
static const uint32_t portAddresses[][4] = {
	{ 0x8066B8D4, 0x806726A4, 0x80673038, 0x80661390 }, /* 0	login error branch */
	{ 0x8065acc0, 0x80662c84, 0x80663618, 0x80651930 }, /* 1	mkw_get_fc_for_current_license */
	{ 0x805c4f88, 0x805d1980, 0x805d20a4, 0x805c0240 }, /* 2	mkw_load_friends_list_from_save */
	{ 0x805c5098, 0x805d1a90, 0x805d21b4, 0x805c0350 }, /* 3	mkw_copy_friends_list_to_save */
	{ 0x80660f28, 0x80662678, 0x8066300c, 0x80651324 }, /* 4	mkw_form_user_record */
	{ 0x809bd938, 0x809c1170, 0x809c2110, 0x809b0750 }, /* 5	friend tracking structure */
	{ 0x80615148, 0x80646FC4, 0x80647958, 0x80635c70 }, /* 6	where to go on connect success */
	{ 0x8061a300, 0x8064cc80, 0x8064D614, 0x8063b92c }, /* 7	what to do when pressing B at friend roster (not a method start) */
	{ 0x8061a204, 0x8064cb84, 0x8064D518, 0x8063b830 }, /* 8	what to do when pressing A on B at the friend roster (not a method start) */
	{ 0x809BD508, 0x809C0E98, 0x809C1E38, 0x809B0478 }, /* 9	menu_data */
	{ 0x8066FCE0, 0x80676ab0, 0x80677444, 0x806657ec }, /* 10	stop ghosts sending */
	{ 0x8065307c, 0x80656b70, 0x80657504, 0x8064581c }, /* 11	mkw_net_main_thread */
	{ 0x805c97f0, 0x805d61e8, 0x805D690C, 0x805c4aa8 }, /* 12	Remove friend button pressed */
	{ 0x805ddcd0, 0x80601d24, 0x806025B0, 0x805f09d0 }, /* 13	Render Popup */
	{ 0x805c11e0, 0x805cd5dc, 0x805cdd00, 0x805bbcc0 }, /* 14	BMG_Print */
	{ 0x80831bcc, 0x8085084c, 0x808511e0, 0x8083f5a0 }, /* 15	On Mario Kart Channel pressed (not a method start) */
	{ 0x80839a2c, 0x8085ab28, 0x8085b4bc, 0x8084987c }, /* 16	On Check Rankings pressed (not a method start) */
	{ 0x80539752, 0x8053E60E, 0x8053EC8E, 0x8052CCE6 }, /* 17	30 Seconds Time Limit Modifier [CLF78] */
	{ 0x8051CF94, 0x80520D88, 0x80521408, 0x8050F42C }, /* 18	No Disconnect [Bully] */
	{ 0x80539758, 0x8053E614, 0x8053EC94, 0x8052CCEC }, /* 19	No Disconnect [Bully] */
	{ 0x80539A30, 0x8053E8EC, 0x8053EF6C, 0x8052CFC4 }, /* 20	No Disconnect [Bully] */
	{ 0x80539B78, 0x8053EA34, 0x8053F0B4, 0x8052D10C }, /* 21	No Disconnect [Bully] */
	{ 0x80539BE8, 0x8053EAA4, 0x8053F124, 0x8052D17C }, /* 22	No Disconnect [Bully] */
	{ 0x805BAD14, 0x805C35FC, 0x805C3C7C, 0x805B1CE0 }, /* 23	Freeze Selection Timer [Bully] */
	{ 0x80539F3C, 0x8053EDF8, 0x8053F478, 0x8052D4D0 }, /* 24	Disconnect at Will [CLF78] */
	{ 0x805DD37C, 0x806013D0, 0x80601C5C, 0x805F007C }, /* 25	Extend Waiting For Others [dirtyfrikandel] */
};

void *get_port_address(int index) {
	uint8_t game_id = *(uint8_t *)0x80000003;
	int index2 =
		game_id == 'E' ? 0 :
		game_id == 'J' ? 1 :
		game_id == 'P' ? 2 :
		game_id == 'K' ? 3 :
		/* deliberate crash! */
		*(volatile int *)0;
	return (void *)portAddresses[index][index2];
}
