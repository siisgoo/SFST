#ifndef ASSETMANAGER_HPP_WQZQCZI9
#define ASSETMANAGER_HPP_WQZQCZI9

#include <SFML/Graphics/Shader.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include <memory>

namespace sfst {

    class AssetManager {
        public:
            AssetManager();

            static sf::Texture&     GetTexture(std::string const& filename);
            static sf::SoundBuffer& GetSoundBuffer(std::string const& filename);
            static sf::Font&        GetFont(std::string const& filename);
            static sf::Shader*      GetShader(std::string const& vsFile, std::string const& fsFile);

            static void setAssetDir(std::string const& dir);

        private:
            std::map<std::string, sf::Texture>                 _textures;
            std::map<std::string, sf::SoundBuffer>             _soundBuffers;
            std::map<std::string, sf::Font>                    _fonts;
            std::map<std::string, std::unique_ptr<sf::Shader>> _shaders;
            std::string _asset_d;

            static AssetManager *sInstance;
    };

}; /* sfst */

#endif /* end of include guard: ASSETMANAGER_HPP_WQZQCZI9 */

