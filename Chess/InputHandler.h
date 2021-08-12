#pragma once
#include "SDL.h"
#include <vector>
#include "Vector2D.h"

/// <summary>
/// Obsluga myszki
/// </summary>
class InputHandler {
public:
	static InputHandler* Instance() {
		if (s_pInstance == 0) s_pInstance = new InputHandler();
		return s_pInstance;
	}
	bool getMouseButtonLeft() { return m_mouseButtonLeft; }
	Vector2D* getMousePosition() { return m_mousePosition; }
	void update();

private:

	InputHandler();
	~InputHandler(){}

	bool m_mouseButtonLeft = false; // czy wciœniêty lewy przycisk myszki

	Vector2D* m_mousePosition; // pozycja myszki

	static InputHandler* s_pInstance;
};
typedef InputHandler TheInputHandler;
