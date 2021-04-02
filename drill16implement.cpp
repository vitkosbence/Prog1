#include "Lines_window.h"

Lines_window :: Lines_window(Point xy, int w ,int h, string title):
	Window{xy,w,h,title},
	nextb{ Point{x_max() - 150,0},70,20,"Next point",cb_next},
	quitb{ Point{x_max() - 70,0},70,20,"Quit",cb_quit },
	color_menu_button{ Point{x_max() - 100,30},100,20,"Color menu",cb_colorm },
	style_menu_button{ Point{x_max() - 100,50},100,20,"Style menu",cb_stylem },
	color_menu{ Point{x_max() - 100,30},100,20,Menu::vertical,"Color menu"},
	style_menu{ Point{x_max() - 100,30},100,20,Menu::vertical,"Style menu" },
	x_in{ Point{x_max() - 320,0},50,20,"Next x" },
	y_in{ Point{x_max() - 210,0},50,20,"Next y" },
	cur_xy{ Point{100,0},100,20,"The current x,y" }
{
	attach(nextb);
	attach(quitb);
	attach(x_in);
	attach(y_in);
	attach(cur_xy);
	attach(lines);
	attach(color_menu_button);
	attach(style_menu_button);
	color_menu.attach(new Button{ Point{0,0},0,0,"red",cb_redp });
	color_menu.attach(new Button{ Point{0,0},0,0,"blue",cb_bluep });
	color_menu.attach(new Button{ Point{0,0},0,0,"green",cb_greenp });
	attach(color_menu);
	color_menu.hide();
	style_menu.attach(new Button{ Point{0,0},0,0,"solid",cb_solidp });
	style_menu.attach(new Button{ Point{0,0},0,0,"dash",cb_dashp });
	style_menu.attach(new Button{ Point{0,0},0,0,"dot",cb_dotp });
	attach(style_menu);
	style_menu.hide();
}

void Lines_window::cb_quit(Address, Address pw) {
	reference_to<Lines_window>(pw).quit();
}

void Lines_window::quit(){
	hide();
}

void Lines_window::cb_next(Address, Address pw) {
	reference_to<Lines_window>(pw).next();
}

void Lines_window::next() {
	int x = x_in.get_int();
	int y = y_in.get_int();
	lines.add(Point{ x,y });
	ostringstream out;
	out << x << " , " << y;
	cur_xy.put(out.str());
	redraw();
}

void Lines_window::cb_colorm(Address, Address pw) {
	reference_to<Lines_window>(pw).colorm();
}

void Lines_window::colorm() {
	color_menu.show();
	color_menu_button.hide();
	style_menu_button.hide();
}

void Lines_window::cb_redp(Address, Address pw) {
	reference_to<Lines_window>(pw).redp();
}

void Lines_window::cb_bluep(Address, Address pw) {
	reference_to<Lines_window>(pw).bluep();
}

void Lines_window::cb_greenp(Address, Address pw) {
	reference_to<Lines_window>(pw).greenp();
}

void Lines_window::redp() {
	lines.set_color(Color::red);
	color_menu.hide();
	color_menu_button.show();
	style_menu_button.show();
}

void Lines_window::bluep() {
	lines.set_color(Color::blue);
	color_menu.hide();
	color_menu_button.show();
	style_menu_button.show();
}

void Lines_window::greenp() {
	lines.set_color(Color::dark_green);
	color_menu.hide();
	color_menu_button.show();
	style_menu_button.show();
}

void Lines_window::cb_stylem(Address, Address pw) {
	reference_to<Lines_window>(pw).stylem();
}

void Lines_window::stylem() {
	style_menu.show();
	color_menu_button.hide();
	style_menu_button.hide();
}

void Lines_window::cb_solidp(Address, Address pw) {
	reference_to<Lines_window>(pw).solidp();
}

void Lines_window::cb_dashp(Address, Address pw) {
	reference_to<Lines_window>(pw).dashp();
}

void Lines_window::cb_dotp(Address, Address pw) {
	reference_to<Lines_window>(pw).dotp();
}

void Lines_window::solidp() {
	lines.set_style(Line_style::solid);
	style_menu.hide();
	color_menu_button.show();
	style_menu_button.show();
}

void Lines_window::dashp() {
	lines.set_style(Line_style::dash);
	style_menu.hide();
	color_menu_button.show();
	style_menu_button.show();
}

void Lines_window::dotp() {
	lines.set_style(Line_style::dot);
	style_menu.hide();
	color_menu_button.show();
	style_menu_button.show();
}