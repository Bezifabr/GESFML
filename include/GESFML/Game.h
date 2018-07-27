#ifndef GESFML_GAME_H
#define GESFML_GAME_H

namespace GESFML
{
    class Game
    {
    public:
        Game();
        void Start();
    private:
        void IterateLoop();
    };
}
#endif // GESFML_GAME_H