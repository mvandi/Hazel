#pragma once

#include "Texture.h"

namespace Hazel {

	class SpriteSheet {
	public:
		SpriteSheet(const Ref<Texture2D>& texture, const glm::vec2& cellSize);

		Ref<Texture2D> Get(float x, float y, const glm::vec2& spriteSize = { 1.0f, 1.0f });

		const glm::vec2& Size() const { return m_Size; }

		Ref<Texture2D> GetTexture() const { return m_Texture; }

		static Ref<SpriteSheet> Create(const Ref<Texture2D>& texture, const glm::vec2& cellSize);

		static Ref<SpriteSheet> Create(const std::string& path, const glm::vec2& cellSize);
	private:
		Ref<Texture2D> m_Texture;
		glm::vec2 m_CellSize;

		glm::vec2 m_Size;
	};

}