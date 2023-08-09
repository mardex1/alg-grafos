#include <iostream>

using namespace std;

class Piscina {
public:
    Piscina(double volume_agua) : volume_agua(volume_agua) {}

    Piscina operator+(const Piscina& outra_piscina) const {
        double novo_volume = volume_agua + outra_piscina.volume_agua;
        return Piscina(novo_volume);
    }

    double obterVolumeAgua() const {
        return volume_agua;
    }

private:
    double volume_agua;
};

int main() {
    Piscina piscina1(50.0);
    Piscina piscina2(30.0);

    Piscina piscina_soma = piscina1 + piscina2;

    cout << "Volume de agua da Piscina 1: " << piscina1.obterVolumeAgua() << " metros cubicos\n";
    cout << "Volume de agua da Piscina 2: " << piscina2.obterVolumeAgua() << " metros cubicos\n";
    cout << "Resultado da soma das Piscinas: " << piscina_soma.obterVolumeAgua() << " metros cubicos\n";

    return 0;
}
