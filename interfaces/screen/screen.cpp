#include "screen.h"

int Screen::track_number = 0;

Screen::Screen() {
    font = *Resources::FontsHolder::getResource("basic_font");
}

void Screen::play_music() {
    if (menu_music.getStatus() == sf::SoundSource::Status::Stopped) {
        ++track_number %= 6;
        menu_music.openFromFile("../../sound/music/track" + std::to_string(track_number) + ".mp3");
        //menu_music.setPlayingOffset(menu_music.getDuration() - sf::seconds(10.f));
        menu_music.play();
    }
Screen::Screen() {
    font = *Resources::FontsHolder::getResource("basic_font");
}
