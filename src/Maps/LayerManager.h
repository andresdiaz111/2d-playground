#ifndef LAYERMANAGER_H
#define LAYERMANAGER_H


class LayerManager
{
    public:
        virtual void Render()=0;
        virtual void Update()=0;

};

#endif // LAYERMANAGER_H
