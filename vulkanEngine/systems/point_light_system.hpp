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
    class PointLightSystem {
    public:
        PointLightSystem(
            VeDevice& device, VkRenderPass renderPass, VkDescriptorSetLayout globalSetLayout);
        ~PointLightSystem();

        PointLightSystem(const PointLightSystem&) = delete;
        PointLightSystem& operator=(const PointLightSystem&) = delete;

        void update(FrameInfo& frameInfo, GlobalUbo& ubo);
        void render(FrameInfo& frameInfo);

    private:
        void createPipelineLayout(VkDescriptorSetLayout globalSetLayout);
        void createPipeline(VkRenderPass renderPass);

        VeDevice& veDevice;

        std::unique_ptr<VePipeline> vePipeline;
        VkPipelineLayout pipelineLayout;
    };
}  // namespace ve