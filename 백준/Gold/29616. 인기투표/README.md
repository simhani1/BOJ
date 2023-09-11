# [Gold V] 인기투표 - 29616 

[문제 링크](https://www.acmicpc.net/problem/29616) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

유클리드 호제법, 수학, 정수론

### 문제 설명

<p>종현은 인생에서 한 번 있을 군 생활을 기념 겸 추억거리로 남겨두기 위해 증명사진을 찍어보았다. 그런데 웬걸! 사진관으로부터 받은 증명사진 속엔 대학생 상병 박종현이 아니라 세상 고초 다 겪은 직업 군인 중사 박종현이 찍혀있었다. 사진에 불만이 생긴 종현은 생활관 동기들에게 하소연 했지만, 동기들은 종현을 놀리기에 바빴다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/726d963a-a8db-42f6-98c6-134ba4feab60/-/preview/" style="max-width: 100%; width: 360px; height: 364px;"></p>

<p>억울한 종현은 SNS에 이 사진이 정말로 자신과 닮았는지 공개 투표를 부쳐, 사진관에서 사진을 이상하게 편집했다고 주장하려고 한다. 투표는 백분율로 공개되고, 철회하거나 번복할 수 없다.</p>

<p>근성은 공개 투표가 친구가 많은 사람의 전유물이라고 생각했기 때문에, 감히 친구가 적은 종현이 SNS에 자신의 증명사진과 공개 투표를 올린 것을 용서하지 못한다. 하지만 근성의 생각과 달리 종현이 새로 사귄 친구가 많을 수도 있으므로, 투표 상황을 지켜보고 종현의 인기를 추정해 보기로 했다.</p>

<p>백분율로 나타나는 투표 결과로부터 전체 투표수를 추측할 수 있으므로, 과거 어느 시점에서의 투표 결과와 현재의 투표 결과를 모두 만족하는 현재의 총투표수를 추정한다.</p>

<p>근성은 종현이 친구가 많으리라 생각하지 않기 때문에, 가능한 총 투표수가 여러 가지라면 근성은 가장 낮은 값을 결과로 받아들일 것이다.</p>

### 입력 

 <p>첫째 줄에 투표 항목의 개수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>100</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1\leq N\leq100$</span></mjx-container>) 과 투표 결과가 표현되는 소수점 자릿수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D443 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>P</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$P$</span></mjx-container> (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D443 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c36"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn><mo>≤</mo><mi>P</mi><mo>≤</mo><mn>6</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0\leq P\leq6$</span></mjx-container>)가 공백으로 구분되어 주어진다.</p>

<p>둘째 줄에 이전 시점, 백분율로 표현되는 각 항목의 투표 결과에 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D443 TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msup><mn>10</mn><mi>P</mi></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$10^P$</span></mjx-container>를 곱한 값 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개가 공백으로 구분되어 주어진다.</p>

<p>셋째 줄에 현재 시점, 백분율로 표현되는 각 항목의 투표 결과에 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D443 TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msup><mn>10</mn><mi>P</mi></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$10^P$</span></mjx-container>를 곱한 값 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개가 공백으로 구분되어 주어진다.</p>

<p>둘째 줄과 셋째 줄에 주어지는 각 값은 반올림이 이루어지지 않은 값이다. 각 시점에서 주어지는 수의 합은 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-texatom size="s" texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D443 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-texatom></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msup><mn>10</mn><mrow data-mjx-texclass="ORD"><mi>P</mi><mo>+</mo><mn>2</mn></mrow></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$10^{P+2}$</span></mjx-container>임이 보장된다.</p>

### 출력 

 <p>근성이 추정하는 이전 시점의 총 투표수와 현재 시점의 총 투표수를 공백을 간격으로 순서대로 출력한다.</p>

