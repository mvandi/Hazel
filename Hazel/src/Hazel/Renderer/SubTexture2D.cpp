#include "hzpch.h"
#include "SubTexture2D.h"

namespace Hazel {

	SubTexture2D::SubTexture2D(const Ref<Texture2D>& texture, const glm::vec2& min, const glm::vec2& max)
		: m_Texture(texture)
	{
		m_TexCoords = Texture2D::CreateTexCoords(min, max);

		m_Width = (int)round( (max.x - min.x) * m_Texture->GetWidth() );
		m_Height = (int)round( (max.y - min.y) * m_Texture->GetHeight() );
	}

	void SubTexture2D::SetData(void* data, uint32_t size)
	{
		HZ_CORE_ASSERT(false, "Unsupported operation on sub textures!");
	}

	void SubTexture2D::Bind(uint32_t slot) const
	{
		m_Texture->Bind(slot);
	}

	Ref<SubTexture2D> SubTexture2D::CreateFromCoords(const Ref<Texture2D>& texture, const glm::vec2& coords, const glm::vec2& cellSize, const glm::vec2& spriteSize)
	{
		glm::vec2 min = { (coords.x * cellSize.x) / texture->GetWidth(), (coords.y * cellSize.y) / texture->GetHeight() };
		glm::vec2 max = { ((coords.x + spriteSize.x) * cellSize.x) / texture->GetWidth(), ((coords.y + spriteSize.y) * cellSize.y) / texture->GetHeight() };
		return CreateRef<SubTexture2D>(texture, min, max);
	}

}