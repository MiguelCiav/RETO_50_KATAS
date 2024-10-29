// ENLACE DEL EJERCICIO: https://www.codewars.com/kata/568d0dd208ee69389d000016/cpp

int rental_car_cost(int d){
  if(d >= 7) {
    return d*40 - 50;
  }
  if(d >= 3) {
    return d*40 - 20;
  }
  return d*40;
}