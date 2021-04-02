#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, string title);
	Open_polyline lines;
private:
	Button nextb;
	Button quitb;
	In_box x_in;
	In_box y_in;
	Out_box cur_xy;
	Button color_menu_button;
	Menu color_menu;
	Button style_menu_button;
	Menu style_menu;
	void next();
	void quit();
	void redp();
	void bluep();
	void greenp();
	void colorm();
	void solidp();
	void dashp();
	void dotp();
	void stylem();
	static void cb_next(Address, Address pw);
	static void cb_quit(Address, Address pw);
	static void cb_redp(Address, Address pw);
	static void cb_bluep(Address, Address pw);
	static void cb_greenp(Address, Address pw);
	static void cb_colorm(Address, Address pw);
	static void cb_solidp(Address, Address pw);
	static void cb_dashp(Address, Address pw);
	static void cb_dotp(Address, Address pw);
	static void cb_stylem(Address, Address pw);
};