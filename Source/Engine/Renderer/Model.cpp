#include "Model.h"
#include "Renderer.h"
namespace piMath {

	void piMath::Model::Draw(Renderer& renderer, const vec2& position, float scale, float rotation)
	{	
		renderer.SetColor(m_color.r, m_color.g, m_color.b);
		
		if (m_points.empty()) {
			return;
		}
		//iterate through all points and draw a line
		
		for (int i = 0; i < m_points.size() - 1; i++) {
			vec2 point1 = (m_points[i].Rotate(rotation) * scale) + position;
			vec2 point2 = (m_points[i + 1].Rotate(rotation) * scale) + position;

			renderer.DrawLine(point1.x, point1.y, point2.x, point2.y);
;		}
		
	}
	/// <summary>
	/// Draws the model using the specified renderer and transformation.
	/// </summary>
	/// <param name="renderer">The renderer used to draw the model.</param>
	/// <param name="transform">The transformation to apply, including position, scale, and rotation.</param>
	void piMath::Model::Draw(Renderer& renderer, const Transform& transform)
	{
		Draw(renderer, transform.position, transform.scale, transform.rotation);
	}

}

