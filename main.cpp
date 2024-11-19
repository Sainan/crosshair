#include <main.hpp>
#include <os.hpp>
#include <RenderTarget.hpp>
#include <Rgb.hpp>
#include <Window.hpp>

int entry(std::vector<std::string>&& args, bool console)
{
	using namespace soup;

	auto w = Window::create("Crosshair Overlay", os::getPrimaryScreenWidth(), os::getPrimaryScreenHeight());
	w.setDrawFunc([](Window, RenderTarget& rt)
	{
		rt.fill(Rgb::GREEN);
		const int x = (rt.width / 2) - 1;
		const int y = (rt.height / 2) - 1;
		if (true)
		{
			rt.drawRect(x + 0, y - 1, 2, 1, Rgb::BLACK); // top
			rt.drawRect(x + 0, y + 2, 2, 1, Rgb::BLACK); // bottom
			rt.drawRect(x + 2, y + 0, 1, 2, Rgb::BLACK); // right
			rt.drawRect(x - 1, y + 0, 1, 2, Rgb::BLACK); // left
			rt.drawRect(x, y, 2, 2, Rgb::WHITE); // centre
		}
		if (false) // Horizontal Centre Line
		{
			rt.drawRect(x, y - 200, 1, 100, Rgb::GREY);
		}
	});
	w.setPos(0, 0);
	w.setTopmost(true);
	w.setClickThrough(true);
	w.setInvisibleColour(Rgb::GREEN);
	w.runMessageLoop();

	return 0;
}

SOUP_MAIN_GUI(entry);
