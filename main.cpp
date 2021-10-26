#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "./Window.cpp"

int main() {
	// Creating the window for the game object
	Window* gameWindow = new Window();

	// Loading GLAD
	gladLoadGL();

	// Setting the viewport of the screen using the width and height of the window
	glViewport(0, 0, gameWindow->getWidth(), gameWindow->getHeight());

	// setting a background color
	glClearColor(0.123f, 0.248f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	gameWindow->swapBuffers();

	// gameloop that only finishes when the window gets terminated
	while (!glfwWindowShouldClose(gameWindow->window)) {
		glfwPollEvents();
	}
	return 0;
}