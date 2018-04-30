# Why do we use Floor.h?

In game explanation:
* Every `floor` contains  **M** `maps`
* **ONE** boss room 
* **ONE** treasure room
* After beating the boss, you go to the next floor

The structure `floor` can be visualized like this:
![Image of Yaktocat](https://lh3.googleusercontent.com/D2frMQzReyOBdrSB1Qfet2YPZVs6fB5JHQ7Gj-ycjGGGrGptni-5hjGuN3PGGBqLUHF7AJ78vlhE5bBuCYYmrbDzYpPHc9BeHET1KyzIFjjS7YWP9_0)

```
class Floor {
public:
    Floor(TileMap * inicio);
    TileMap * inicio;
    Floor *prox;
    void generateFloor(int tam);
};
```
To use `Floor.h` you need a starting point, this starting point is a `map`. After passing an _empty map_ you can `generateFloor` passing the size of your floor, this can be a random number. 
You don't need to set `Floor *prox`, this will be set with the class `Run`.






