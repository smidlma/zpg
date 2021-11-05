#include <Camera.hpp>
#include <IObserver.hpp>

void ISubject::registerObserver(IObserver *ob) { observers.push_back(ob); };
void ISubject::removeObserver(IObserver *ob) { observers.remove(ob); };
void ISubject::notify(Camera *camera) {
  for (IObserver *ob : observers) {
    ob->update(camera);
  }
};