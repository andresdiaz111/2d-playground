#ifndef LAYERMANAGER_H
#define LAYERMANAGER_H


class LayerManager
{
    public:
        virtual void RenderLayer()=0;
        virtual void UpdateLayer()=0;

};

#endif // LAYERMANAGER_H
