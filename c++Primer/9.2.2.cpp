//9.7 int의 vector에 색인으로 어떤 타입을 사용해햐 하는가?
//size_t, size_type을 사용한다 int는 크기가 큰 벡터에 사용하면 오버플로우를 일으킬 수 있다.

//9.8 string의 list에 속한 요소를 읽기위해 어떤 타입을 사용해야 하는가??
// A. vector<string> , list<string> string을 포함하는 컨테이너를 사용해야한다.