#pragma once

#include "..\\ve_camera.hpp"
#include "..\\ve_device.hpp"
#include "..\\ve_frame_info.hpp"
#include "..\\ve_game_object.hpp"
#include "..\\ve_pipeline.hpp"

// std
#include <memory>
#include <vector>

namespace ve {
    class SimpleRenderSystem {
    public:
        SimpleRenderSystem(
            VeDevice& device, VkRenderPass renderPass, VkDescriptorSetLayout globalSetLayout);
        ~SimpleRenderSystem();

        SimpleRenderSystem(const SimpleRenderSystem&) = delete;
        SimpleRenderSystem& operator=(const SimpleRenderSystem&) = delete;

        void renderGameObjects(FrameInfo& frameInfo);

    private:
        void createPipelineLayout(VkDescriptorSetLayout globalSetLayout);
        void createPipeline(VkRenderPass renderPass);

        VeDevice& veDevice;

        std::unique_ptr<VePipeline> vePipeline;
        VkPipelineLayout pipelineLayout;
    };
}  // namespace ve