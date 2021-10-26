#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
	// TOOD: 
	// sa facem meniu de setari inainte sa intre in joc si sa iti poti seta rezolutia, sa nu mai fie asta pusa default
private:
	int width = 800;
	int height = 600;

public:
	GLFWwindow* window;
	Window() {
		// Initiating the window and its context
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		// Creating the proper window.
		this->window = glfwCreateWindow(this->width, this->height, "Scrabble Gamification", NULL, NULL);

		if (!this->window) {
			std::cout << "Failed to create the instance of window. Terminating...\n";
			glfwTerminate();
		}

		// Telling GLFW what is the window to display
		glfwMakeContextCurrent(this->window);
	}

	// Window destructor, should only get called when the game is closed
	~Window() {
		glfwDestroyWindow(this->window);
		glfwTerminate();
	}

	// A method to swap the back buffer with the front buffer
	// Ref: https://learnopengl.com/Advanced-OpenGL/Framebuffers
	void swapBuffers() {
		glfwSwapBuffers(this->window);
	}

	// getters
	int getHeight() {
		return this->height;
	}

	int getWidth() {
		return this->width;
	}
}; 