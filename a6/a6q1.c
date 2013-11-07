#include <stdio.h>
#include <limits.h>
#define min 3

int main(void){

  //get length of variable length array
  int len;
  scanf("%d\n", &len);
  if(len<min){
    printf("At least %d points are required!\n", min);
    return 1;
  }
  int S[len][2];
  //S[i][0] is the X coor
  //S[i][1] is the Y coor

  /*read len number of points from into 2D array
   and get maxY point at same time */
  int i;
  int maxY=INT_MIN;
  int top=0; //index of top most point
  for(i=0; i<len; i++){
    int x,y;
    if(scanf("%d %d\n", &x, &y)!=2){
      printf("invalid input\n");
      return 1;
    }
    if(y>maxY){
      maxY=y;
      top=i;
    }
    //bonus point section--------------------------
    if(y==maxY){ //make sure we have left most top
      if(x<S[top][0])
	top=i;
    }
    //end bonus point section----------------------
    S[i][0]=x;
    S[i][1]=y;
  }
  
  //it's possible all points are the convex hull
  int C[len];
  C[0]=top; //top is starting vertice in convex hull
  int numVerts=1;

  //find remaining convex hull verticies till we're back at top point
  for(i=0; i<len; i++){
    if(i!=top){
      int k=0;//index of next potential vertice
      if(k==C[numVerts-1])
	k++;
      int j;
      for(j=0; j<len; j++){
	if(j!=C[numVerts-1] && j!=k){
	  int tmp = (S[k][0]-S[C[numVerts-1]][0])*(S[j][1]-S[C[numVerts-1]][1])
	    -(S[j][0]-S[C[numVerts-1]][0])*(S[k][1]-S[C[numVerts-1]][1]);
	  if(tmp>0)
	    k=j;
	  //bonus point section-------------------------------------
	  else if(tmp==0){ //multiple points on a line convex hull boundary
	    int kVal = (S[k][0]-S[top][0]) //*(S[k][0]-S[top][0]) 
	      + (S[k][1]-S[top][1]); //*(S[k][1]-S[top][1]);
	    int jVal = (S[j][0]-S[top][0]) //*(S[j][0]-S[top][0]) 
	      + (S[j][1]-S[top][1]); //*(S[k][1]-S[top][1]);
	    if(jVal>kVal)//compare these relative indicators of vector length
	      k=j;
	  }
	  //end bonus point section---------------------------------
	}
      }
      if(k!=top){ //make sure we're not back at top point
	C[numVerts]=k;
	++numVerts;
      }
      else //if we are, we're done!
	break;
    }
  }
  
  //output number of vertices of the convex hull
  printf("%d\n", numVerts);

  //then output the coordinates for these vertices
  for(i=0; i<numVerts; i++)
    printf("%d %d\n", S[C[i]][0], S[C[i]][1]);

  return 0;
}
