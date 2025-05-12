#pragma once

class Student
{
    char nume[256];
    float mate,eng,ist,medie;

    public:
        void Ia_Nume(char nume[256]);
        char* Dai_Nume();
        
        void Ia_Mate(float mate);
        float Dai_Mate();

        void Ia_Eng(float eng);
        float Dai_Eng();

        void Ia_Ist(float ist);
        float Dai_Ist();

        float Dai_Medie();



};
