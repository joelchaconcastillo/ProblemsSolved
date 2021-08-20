#include <bits/stdc++.h>
#define EPS 1.0e-9
#define DEG_to_RAD(x)(x*M_PI/180.0)
using namespace std;
struct point_i{int x, y;
  point_i(){x=y=0;}
  point_i(int _x, int _y):x(_x), y(_y){}};
//struct point {double x, y;
//  point(){ x=y=0.0;}
//  point(double _x, double _y): x(_x), y(_y){}};

//struct point{ double x, y;
//  point(){ x=y=0.0;}
//  point(double _x, double _y): x(_x), y(_y){}
//  bool operator < (point other) const{
//   if(fabs(x-other.x)>EPS) return x<other.x;
//   return y < other.y;} 
//  };
struct point{ double x,y;
   point() { x = y = 0.0;}
   point(double _x, double _y): x(_x), y(_y) {}
   bool operator == (point other) const{
   return (fabs(x-other.x) < EPS && (fabs(y-other.y) < EPS) ); 
   }};
struct line{ double a,b,c;};
struct vec{double x,y;
        vec(double _x, double _y):x(_x), y(_y){}};
vec toVec(point a, point b){
     return vec(b.x - a.x, b.y - a.y);}
vec scale(vec v, double s){
  return vec(v.x*s, v.y*s);}
point translate(point p, vec v){
   return point(p.x + v.x, p.y + v.y);}



double dist(point p1, point p2)
{ return hypot(p1.x-p2.x, p1.y-p2.y); }

point rotate(point p, double theta){
  double rad = DEG_to_RAD(theta);
  return point( p.x*cos(rad) - p.y*sin(rad), p.x*sin(rad) + p.y*cos(rad));
}
void pointsToLine(point p1, point p2, line &l){
   if(fabs(p1.x-p2.x)<EPS){
     l.a=1.0; l.b=0.0; l.c=-p1.x;
   }else{
    l.a = -(double)(p1.y-p2.y)/(p1.x-p2.x);
    l.b = 1.0;
    l.c = -(double)(l.a*p1.x) - p1.y;
   }
}
bool areParallel(line l1, line l2){
   return (fabs(l1.a-l2.a)<EPS) && (fabs(l1.b-l2.b)<EPS);}

bool areSame(line l1, line l2){
  return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);}
bool areIntersect(line l1, line l2, point &p){
   if(areParallel(l1, l2)) return false;
   p.x=(l2.b*l1.c - l1.b*l2.c) / (l2.a*l1.b - l1.a*l2.b);
   if(fabs(l1.b>EPS)) p.y = -(l1.a*p.x + l1.c);///l1.b;
   else p.y = -(l2.a*p.x + l2.c);///l2.b;
  return true;
}
double dot(vec a, vec b){ return (a.x*b.x + a.y*b.y);}
double norm_sq(vec v){ return v.x*v.x + v.y*v.y;}

double distToLine(point p, point a, point b, point &c){
  vec ap=toVec(a,p), ab=toVec(a,b);
  double u = dot(ap, ab)/norm_sq(ab);
  c = translate(a, scale(ab, u));
  return dist(p, c);
}
double distToLineSegment(point p, point a, point b, point &c){
   vec ap=toVec(a,p), ab=toVec(a,b);
   double u = dot(ap, ab)/norm_sq(ab);
   if(u<0.0){ c=point(a.x, a.y);
    return dist(p,a);}
   if(u>1.0){ c=point(b.x, b.y);
    return dist(p, b);}
   return distToLine(p, a, b, c);
}
double angle(point a, point o, point b){
   vec oa=toVec(o,a), ob=toVec(o,b);
   return acos(dot(oa, ob)/sqrt(norm_sq(oa)*norm_sq(ob)));}
double cross(vec a, vec b){ return a.x*b.y - a.y*b.x;}
bool ccw(point p, point q, point r){
   return cross(toVec(p,q), toVec(p,r))>0;}
bool collinear(point p, point q, point r){
   return fabs(cross(toVec(p,q), toVec(p,r))) < EPS;}
int insideCircle(point_i p, point_i c, int r){
   int dx=p.x - c.x, dy=p.y-c.y;
   int Euc = dx*dx + dy*dy, rSq=r*r;
   return Euc < rSq?0:Euc==rSq?1:2;}
bool circle2PtsRad(point p1, point p2, double r, point &c){
  double d2=(p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
  double det=r*r/d2-0.25;
  if(det < 0.0) return false;
  double h =sqrt(det);
  c.x=(p1.x+p2.x)*0.5+(p1.y-p2.y)*h;
  c.y=(p1.y+p2.y)*0.5+(p2.x-p1.x)*h;
  return true;
}
double perimeter(double a, double b, double c){
 return a+b+c;}
double area(double a, double b, double c){
   double s = 0.5*perimeter(a, b, c);
return sqrt(s*(s-a)*(s-b)*(s-c));}
double rInCircle(double ab, double bc, double ca){
     return area(ab, bc, ca)/(0.5*perimeter(ab,bc,ca));}
double rInCircle(point a, point b, point c){
   return rInCircle(dist(a,b), dist(b,c), dist(c,a));}
int inCircle(point p1, point p2, point p3, point &ctr, double &r){
  r = rInCircle(p1, p2, p3);
  if(fabs(r)<EPS) return 0;
  line l1, l2;
  double ratio = dist(p1, p2)/dist(p1, p3);
  point p = translate(p2, scale(toVec(p2, p3), ratio/(1.0+ratio)));
  pointsToLine(p1, p, l1);

  ratio = dist(p2, p1)/dist(p2, p3);
  p = translate(p1, scale(toVec(p1, p3), ratio/(1.0+ratio)));
  pointsToLine(p2, p, l2);
  areIntersect(l1, l2, ctr);
  return 1;
}
double rCircumCircle(double ab, double bc, double ca){
   return ab*bc*ca/(4.0*area(ab, bc, ca));}
double rCircumCircle(point a, point b, point c){
  return rCircumCircle(dist(a,b), dist(b,c), dist(c,a));
}

double perimeter(const vector<point> &P){
  double result=0.0;
  for(int i = 0; i < (int)P.size()-1; i++)
    result += dist(P[i], P[i+1]);
  return result;}
double area(const vector<point> &P){
   double result = 0.0, x1, y1, x2, y2;
   for(int i = 0; i < (int)P.size()-1; i++){
      x1=P[i].x; x2=P[i+1].x;
      y1=P[i].y; y2=P[i+1].y;
      result += (x1*y2 - x2*y1);
   }
  return fabs(result)/2.0;
}
bool isConvex(const vector<point> &P){
   int sz=(int)P.size();
   if(sz <= 3) return false;
   bool isLeft=ccw(P[0], P[1], P[2]);
   for(int i = 1; i < sz-1; i++)
     if(ccw(P[i], P[i+1], P[(i+2)==sz?1:i+2])!=isLeft)
	return false;
   return true;
}
bool inPolygon(point pt, const vector<point> &P){
   if((int)P.size() == 0) return false;
   double sum=0.0;
   for(int i = 0; i < (int)P.size()-1; i++){
      if(ccw(pt, P[i], P[i+1]))
	sum +=angle(P[i], pt, P[i+1]);
      else sum -= angle(P[i], pt, P[i+1]);}
   return fabs(fabs(sum)-2*M_PI)<EPS;
}
point lineItersectSeg(point p, point q, point A, point B){
   double a=B.y-A.y;
   double b=A.x-B.x;
   double c=B.x*A.y-A.x*B.y;
   double u=fabs(a*p.x + b*p.y + c);
   double v=fabs(a*q.x + b*q.y + c);
   return point((p.x*v + q.x*u)/(u+v), (p.y*v + q.y*u)/(u+v));
}
vector<point> cutPolygon(point a, point b, const vector<point> &Q){
  vector<point> P;
  for(int i = 0; i < (int)Q.size(); i++){
     double left1=cross(toVec(a,b), toVec(a,Q[i])), left2=0;
     if( i!= (int)Q.size()-1) left2 = cross(toVec(a, b), toVec(a, Q[i+1]));
     if(left1 > -EPS) P.push_back(Q[i]);
     if(left1*left2 < -EPS) P.push_back(lineItersectSeg(Q[i], Q[i+1], a, b));
  }
  if(!P.empty() && !(P.back() == P.front())) P.push_back(P.front());
  return P;
}
////Graham scan algorithm...
point pivot(0, 0);
bool angleCmp(point a, point b){
   if(collinear(pivot, a, b)) return dist(pivot, a) < dist(pivot, b);
   double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
   double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
   return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}
vector<point> CH(vector<point> P){
  int i, j, n=(int)P.size();
  if(n<=3){
     if(!(P[0]== P[n-1])) P.push_back(P[0]);
     return P;
  }

  int P0=0;
  for(i=1; i < n; i++)
    if(P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
	P0=i;
  point temp = P[0]; P[0] = P[P0]; P[P0]=temp;
  pivot = P[0];
  sort(++P.begin(), P.end(), angleCmp);
  vector<point> S;
  S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]);
  i=2;
  while(i<n){
    j=(int)S.size()-1;
    if(ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]);
    else S.pop_back();} 
  return S;
}
int main()
{
  return 0;
}
