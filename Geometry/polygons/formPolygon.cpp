bool possible(double angle){
  if(angle <= 0 || angle >= 180) return false;

  double sides = 360.0/(180.0-angle);

  return (sides == static_cast<int>(sides) && sides >= 3);
}
