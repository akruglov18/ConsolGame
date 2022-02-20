#pragma once
#include "creature.h"
#include "Player/player.h"
#include "field.h"
#include <functional>

class Skill {
public:
    Skill(std::function<void(Player&)> _player_func, 
          std::function<void(Player&)> _enemy_func = nullptr,
          std::function<void(Player&)> _environment_func = nullptr);

    std::function<void(Player&)> player_func;
    std::function<void(Player&)> emeny_func;
    std::function<void(Player&)> environment_func;
};

class Skills_Functions {
public:
////VITALITY///////////////////////////////////////////////////////////////////////////////////////
    // ����� �� �����: ���� � ����� ������ �� ������� � �� ������, � �������� ������� ��� ��������
    // � ���� ���� ��������� �����, �� ���� � ������, ����� �������� �������
    // !!! �� ������ ����� ����� ����� ������ ���������� ��������
    static void vitality5(Player& p);

    // ������� �������: ����� �� ���� � 5 ��� ������ �� ���������� �������� �� ������
    // ��� ��������������� �� 25% ������ ��������
    static void vitality10(Player& p);

    // ������� �������: ������ � ������� �����
    // ������ ��������� �������� ��������� ����������� �������� �� 10
    static void vitality15(Player& p);

////MELEE//////////////////////////////////////////////////////////////////////////////////////////
};