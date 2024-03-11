#pragma once

#include "ve_descriptors.hpp"
#include "ve_device.hpp"
#include "ve_game_object.hpp"
#include "ve_renderer.hpp"
#include "ve_window.hpp"

// std
#include <memory>
#include <vector>

namespace ve {
	class FirstApp {
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		FirstApp();
		~FirstApp();

		FirstApp(const FirstApp&) = delete;
		FirstApp& operator=(const FirstApp&) = delete;

		void run();

	private:
		void loadGameObjects();

		VeWindow veWindow{ WIDTH, HEIGHT, "Vulkan Tutorial" };
		VeDevice veDevice{ veWindow };
		VeRenderer veRenderer{ veWindow, veDevice };

		// note: order of declarations matters
		std::unique_ptr<VeDescriptorPool> globalPool{};
		VeGameObject::Map gameObjects;
	};
}  // namespace ve