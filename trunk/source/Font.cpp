#define WINVER 0x0501
#define _WIN32_WINNT 0x501
#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>

#include "Device.h"
#include "Sprite.h"
#include "Font.h"
#include "Utils.h"

#include <vcclr.h>

namespace SlimDX
{
namespace Direct3D
{
	Font::Font( ID3DXFont* font )
	{
		if( font == NULL )
			throw gcnew ArgumentNullException( "font" );

		m_Font = font;
	}

	Font::Font( Device^ device, int height, int width, FontWeight weight, int mipLevels, bool italic,
		CharacterSet charSet, Precision outputPrecision, FontQuality quality,
		PitchAndFamily pitchAndFamily, String^ faceName )
	{
		ID3DXFont* font;
		pin_ptr<const wchar_t> pinned_name = PtrToStringChars( faceName );

		HRESULT hr = D3DXCreateFont( device->InternalPointer, height, width, (UINT) weight, mipLevels, italic, (DWORD) charSet,
			(DWORD) outputPrecision, (DWORD) quality, (DWORD) pitchAndFamily, (LPCWSTR) pinned_name, &font );
		GraphicsException::CheckHResult( hr );

		m_Font = font;
	}

	int Font::DrawText( Sprite^ sprite, String^ text, System::Drawing::Rectangle rect, DrawTextFormat format, int color )
	{
		ID3DXSprite* spritePtr = sprite != nullptr ? sprite->InternalPointer : NULL;
		pin_ptr<const wchar_t> pinned_text = PtrToStringChars( text );
		RECT nativeRect = { rect.Left, rect.Top, rect.Right, rect.Bottom };

		return m_Font->DrawTextW( spritePtr, (LPCWSTR) pinned_text, text->Length, &nativeRect, (DWORD) format, color );
	}

	int Font::DrawText( Sprite^ sprite, String^ text, System::Drawing::Rectangle rect, DrawTextFormat format, Color color )
	{
		return DrawText( sprite, text, rect, format, color.ToArgb() );
	}

	int Font::DrawText( Sprite^ sprite, String^ text, int x, int y, int color )
	{
		System::Drawing::Rectangle rect( x, y, 0, 0 );
		return DrawText( sprite, text, rect, DrawTextFormat::NoClip, color );
	}

	int Font::DrawText( Sprite^ sprite, String^ text, int x, int y, Color color )
	{
		return DrawText( sprite, text, x, y, color.ToArgb() );
	}

	System::Drawing::Rectangle Font::MeasureString( Sprite^ sprite, String^ text, DrawTextFormat format )
	{
		ID3DXSprite* spritePtr = sprite != nullptr ? sprite->InternalPointer : NULL;
		pin_ptr<const wchar_t> pinned_text = PtrToStringChars( text );
		RECT nativeRect;

		m_Font->DrawTextW( spritePtr, (LPCWSTR) pinned_text, text->Length, &nativeRect, 
			(DWORD) (format | DrawTextFormat::CalcRect), 0 );
	
		return System::Drawing::Rectangle( nativeRect.left, nativeRect.top, 
			nativeRect.right - nativeRect.left, nativeRect.bottom - nativeRect.top );
	}

	void Font::PreloadCharacters( int first, int last )
	{
		HRESULT hr = m_Font->PreloadCharacters( first, last );
		GraphicsException::CheckHResult( hr );
	}

	void Font::PreloadGlyphs( int first, int last )
	{
		HRESULT hr = m_Font->PreloadGlyphs( first, last );
		GraphicsException::CheckHResult( hr );
	}

	void Font::PreloadText( String^ text )
	{
		pin_ptr<const wchar_t> pinned_text = PtrToStringChars( text );
		HRESULT hr = m_Font->PreloadTextW( (LPCWSTR) pinned_text, text->Length );
		GraphicsException::CheckHResult( hr );
	}

	void Font::OnLostDevice()
	{
		HRESULT hr = m_Font->OnLostDevice();
		GraphicsException::CheckHResult( hr );
	}

	void Font::OnResetDevice()
	{
		HRESULT hr = m_Font->OnResetDevice();
		GraphicsException::CheckHResult( hr );
	}

	FontDescription Font::Description::get()
	{
		D3DXFONT_DESC desc;
		
		HRESULT hr = m_Font->GetDesc( &desc );
		GraphicsException::CheckHResult( hr );

		FontDescription outDesc;
		outDesc.Height = desc.Height;
		outDesc.Width = desc.Width;
		outDesc.Weight = (FontWeight) desc.Weight;
		outDesc.MipLevels = desc.MipLevels;
		outDesc.Italic = desc.Italic > 0;
		outDesc.CharSet = (CharacterSet) desc.CharSet;
		outDesc.OutputPrecision = (Precision) desc.OutputPrecision;
		outDesc.Quality = (FontQuality) desc.Quality;
		outDesc.PitchAndFamily = (PitchAndFamily) desc.PitchAndFamily;
		outDesc.FaceName = gcnew String( desc.FaceName );

		return outDesc;
	}

	IntPtr Font::DeviceContext::get()
	{
		return (IntPtr) m_Font->GetDC();
	}
}
}
