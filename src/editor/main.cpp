#include "EditorApplication.h"

int main() {
	Editor::EditorApplication app;
	if (app.init(1280, 720, "Editor")) {
		app.run();
	}
	return 0;
}