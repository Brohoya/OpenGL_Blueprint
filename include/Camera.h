#ifndef CAMERA_H
#define CAMERA_H

#include "utils.h"

class Camera
{
private:

	glm::vec3				position;					// Position de la camera
	float					sensitivity;				// Sensibilite de la souris
	float					fov;						// Champ de vision
	glm::mat4				view;						// Matrice de vue
	glm::mat4				projection;					// Matrice de projection
	glm::vec3				direction;					// Direction de la camera
	float					yaw;						// Deplacement horizontal de la direction
	float					pitch;						// D�placement vertical de la direction

public:

	static constexpr float	default_fov = pi / 4.f;		// Champs de vision par defaut
	static constexpr float	default_sensitivity = 0.2f;	// Champs de vision par defaut

	Camera(const Camera& other);
	Camera(const glm::vec3& position = glm::vec3(0.f, 0.f, 0.f), float sensitivity = default_sensitivity, float fov = default_fov);

	Camera& operator=(const Camera& other);

	void					look(const glm::ivec2& mouse_pos);
	glm::mat4				get_matrix() const;
	void					set_position(const glm::vec3& position);
	glm::vec3				get_position() const;
	float					get_yaw() const;
	float					get_pitch() const;
	glm::vec3				get_direction() const;
	void					invert(float mirror_level);
	void					change_resolution(float width, float height);
};

#endif