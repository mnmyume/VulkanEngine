#pragma once

#include "ve_model.hpp"

// libs
#include <glm/gtc/matrix_transform.hpp>

// std
#include <memory>
#include <unordered_map>

namespace ve {

    struct TransformComponent {
        glm::vec3 translation{};
        glm::vec3 scale{ 1.f, 1.f, 1.f };
        glm::vec3 rotation{};

        // Matrix corrsponds to Translate * Ry * Rx * Rz * Scale
        // Rotations correspond to Tait-bryan angles of Y(1), X(2), Z(3)
        glm::mat4 mat4();

        glm::mat3 normalMatrix();
    };

    struct PointLightComponent {
        float lightIntensity = 1.0f;
    };

    class VeGameObject {
    public:
        using id_t = unsigned int;
        using Map = std::unordered_map<id_t, VeGameObject>;

        static VeGameObject createGameObject() {
            static id_t currentId = 0;
            return VeGameObject{ currentId++ };
        }

        static VeGameObject makePointLight(
            float intensity = 10.f, float radius = 0.1f, glm::vec3 color = glm::vec3(1.f));

        VeGameObject(const VeGameObject&) = delete;
        VeGameObject& operator=(const VeGameObject&) = delete;
        VeGameObject(VeGameObject&&) = default;
        VeGameObject& operator=(VeGameObject&&) = default;

        id_t getId() { return id; }

        glm::vec3 color{};
        TransformComponent transform{};

        // Optional pointer components
        std::shared_ptr<VeModel> model{};
        std::unique_ptr<PointLightComponent> pointLight = nullptr;

    private:
        VeGameObject(id_t objId) : id{ objId } {}

        id_t id;
    };
}  // namespace ve