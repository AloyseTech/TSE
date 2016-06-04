#define MAX_ENEMY_PROJECTILES 3

class ShootingEnemy : public TSE_Sprite
{
  public :
    void shoot(TSE_Sprite target);

    TSE_Sprite projectiles[MAX_ENEMY_PROJECTILES];

  private :
    uint8_t activeProjectiles = 0;
};

void ShootingEnemy::shoot(TSE_Sprite target)
{

}


