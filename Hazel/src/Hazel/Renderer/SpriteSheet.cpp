#include "hzpch.h"
#include "SpriteSheet.h"

#include "SubTexture2D.h"

namespace Hazel {

	SpriteSheet::SpriteSheet(const Ref<Texture2D>& texture, const glm::vec2& cellSize)
		: m_Texture(texture), m_CellSize(cellSize)
	{
		m_Size = { m_Texture->GetWidth() / m_CellSize.x, m_Texture->GetHeight() / m_CellSize.y };
	}

	Ref<Texture2D> SpriteSheet::Get(float x, float y, const glm::vec2& spriteSize)
	{
		return SubTexture2D::CreateFromCoords(m_Texture, { x, y }, m_CellSize, spriteSize);
	}

	Ref<SpriteSheet> SpriteSheet::Create(const Ref<Texture2D>& texture, const glm::vec2& cellSize)
	{
		return CreateRef<SpriteSheet>(texture, cellSize);
	}

	Ref<SpriteSheet> SpriteSheet::Create(const std::string& path, const glm::vec2& cellSize)
	{
		return Create(Texture2D::Create(path), cellSize);
	}

}