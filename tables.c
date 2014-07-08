// Precalculated Look-up tables
// Generated by zxmaze3dgenprecalc.Zxmaze3dGenPrecalc 

#include <stdlib.h>

// f_dir_sin
int f_dir_sin[] = {
0,
6,
13,
19,
25,
31,
38,
44,
50,
56,
62,
68,
74,
80,
86,
92,
98,
104,
109,
115,
121,
126,
132,
137,
142,
147,
152,
157,
162,
167,
172,
177,
181,
185,
190,
194,
198,
202,
206,
209,
213,
216,
220,
223,
226,
229,
231,
234,
237,
239,
241,
243,
245,
247,
248,
250,
251,
252,
253,
254,
255,
255,
256,
256,
256,
256,
256,
255,
255,
254,
253,
252,
251,
250,
248,
247,
245,
243,
241,
239,
237,
234,
231,
229,
226,
223,
220,
216,
213,
209,
206,
202,
198,
194,
190,
185,
181,
177,
172,
167,
162,
157,
152,
147,
142,
137,
132,
126,
121,
115,
109,
104,
98,
92,
86,
80,
74,
68,
62,
56,
50,
44,
38,
31,
25,
19,
13,
6,
0,
-6,
-13,
-19,
-25,
-31,
-38,
-44,
-50,
-56,
-62,
-68,
-74,
-80,
-86,
-92,
-98,
-104,
-109,
-115,
-121,
-126,
-132,
-137,
-142,
-147,
-152,
-157,
-162,
-167,
-172,
-177,
-181,
-185,
-190,
-194,
-198,
-202,
-206,
-209,
-213,
-216,
-220,
-223,
-226,
-229,
-231,
-234,
-237,
-239,
-241,
-243,
-245,
-247,
-248,
-250,
-251,
-252,
-253,
-254,
-255,
-255,
-256,
-256,
-256,
-256,
-256,
-255,
-255,
-254,
-253,
-252,
-251,
-250,
-248,
-247,
-245,
-243,
-241,
-239,
-237,
-234,
-231,
-229,
-226,
-223,
-220,
-216,
-213,
-209,
-206,
-202,
-198,
-194,
-190,
-185,
-181,
-177,
-172,
-167,
-162,
-157,
-152,
-147,
-142,
-137,
-132,
-126,
-121,
-115,
-109,
-104,
-98,
-92,
-86,
-80,
-74,
-68,
-62,
-56,
-50,
-44,
-38,
-31,
-25,
-19,
-13,
-6};
// f_dir_cos
int f_dir_cos[] = {
256,
256,
256,
255,
255,
254,
253,
252,
251,
250,
248,
247,
245,
243,
241,
239,
237,
234,
231,
229,
226,
223,
220,
216,
213,
209,
206,
202,
198,
194,
190,
185,
181,
177,
172,
167,
162,
157,
152,
147,
142,
137,
132,
126,
121,
115,
109,
104,
98,
92,
86,
80,
74,
68,
62,
56,
50,
44,
38,
31,
25,
19,
13,
6,
0,
-6,
-13,
-19,
-25,
-31,
-38,
-44,
-50,
-56,
-62,
-68,
-74,
-80,
-86,
-92,
-98,
-104,
-109,
-115,
-121,
-126,
-132,
-137,
-142,
-147,
-152,
-157,
-162,
-167,
-172,
-177,
-181,
-185,
-190,
-194,
-198,
-202,
-206,
-209,
-213,
-216,
-220,
-223,
-226,
-229,
-231,
-234,
-237,
-239,
-241,
-243,
-245,
-247,
-248,
-250,
-251,
-252,
-253,
-254,
-255,
-255,
-256,
-256,
-256,
-256,
-256,
-255,
-255,
-254,
-253,
-252,
-251,
-250,
-248,
-247,
-245,
-243,
-241,
-239,
-237,
-234,
-231,
-229,
-226,
-223,
-220,
-216,
-213,
-209,
-206,
-202,
-198,
-194,
-190,
-185,
-181,
-177,
-172,
-167,
-162,
-157,
-152,
-147,
-142,
-137,
-132,
-126,
-121,
-115,
-109,
-104,
-98,
-92,
-86,
-80,
-74,
-68,
-62,
-56,
-50,
-44,
-38,
-31,
-25,
-19,
-13,
-6,
0,
6,
13,
19,
25,
31,
38,
44,
50,
56,
62,
68,
74,
80,
86,
92,
98,
104,
109,
115,
121,
126,
132,
137,
142,
147,
152,
157,
162,
167,
172,
177,
181,
185,
190,
194,
198,
202,
206,
209,
213,
216,
220,
223,
226,
229,
231,
234,
237,
239,
241,
243,
245,
247,
248,
250,
251,
252,
253,
254,
255,
255,
256,
256};
// ctan of direction, saturated
int f_dir_ctan[] = {
32767,
10428,
5211,
3471,
2599,
2076,
1726,
1475,
1287,
1140,
1022,
925,
844,
775,
715,
664,
618,
578,
541,
509,
479,
452,
427,
404,
383,
363,
345,
328,
312,
297,
282,
269,
256,
244,
232,
221,
210,
200,
190,
180,
171,
162,
153,
145,
137,
129,
121,
113,
106,
99,
92,
85,
78,
71,
64,
57,
51,
44,
38,
32,
25,
19,
13,
6,
0,
-6,
-13,
-19,
-25,
-32,
-38,
-44,
-51,
-57,
-64,
-71,
-78,
-85,
-92,
-99,
-106,
-113,
-121,
-129,
-137,
-145,
-153,
-162,
-171,
-180,
-190,
-200,
-210,
-221,
-232,
-244,
-256,
-269,
-282,
-297,
-312,
-328,
-345,
-363,
-383,
-404,
-427,
-452,
-479,
-509,
-541,
-578,
-618,
-664,
-715,
-775,
-844,
-925,
-1022,
-1140,
-1287,
-1475,
-1726,
-2076,
-2599,
-3471,
-5211,
-10428,
-32768,
10428,
5211,
3471,
2599,
2076,
1726,
1475,
1287,
1140,
1022,
925,
844,
775,
715,
664,
618,
578,
541,
509,
479,
452,
427,
404,
383,
363,
345,
328,
312,
297,
282,
269,
256,
244,
232,
221,
210,
200,
190,
180,
171,
162,
153,
145,
137,
129,
121,
113,
106,
99,
92,
85,
78,
71,
64,
57,
51,
44,
38,
32,
25,
19,
13,
6,
0,
-6,
-13,
-19,
-25,
-32,
-38,
-44,
-51,
-57,
-64,
-71,
-78,
-85,
-92,
-99,
-106,
-113,
-121,
-129,
-137,
-145,
-153,
-162,
-171,
-180,
-190,
-200,
-210,
-221,
-232,
-244,
-256,
-269,
-282,
-297,
-312,
-328,
-345,
-363,
-383,
-404,
-427,
-452,
-479,
-509,
-541,
-578,
-618,
-664,
-715,
-775,
-844,
-925,
-1022,
-1140,
-1287,
-1475,
-1726,
-2076,
-2599,
-3471,
-5211,
-10428};
// tan of direction, saturated
int f_dir_tan[] = {
0,
6,
13,
19,
25,
32,
38,
44,
51,
57,
64,
71,
78,
85,
92,
99,
106,
113,
121,
129,
137,
145,
153,
162,
171,
180,
190,
200,
210,
221,
232,
244,
256,
269,
282,
297,
312,
328,
345,
363,
383,
404,
427,
452,
479,
509,
541,
578,
618,
664,
715,
775,
844,
925,
1022,
1140,
1287,
1475,
1726,
2076,
2599,
3471,
5211,
10428,
32767,
-10428,
-5211,
-3471,
-2599,
-2076,
-1726,
-1475,
-1287,
-1140,
-1022,
-925,
-844,
-775,
-715,
-664,
-618,
-578,
-541,
-509,
-479,
-452,
-427,
-404,
-383,
-363,
-345,
-328,
-312,
-297,
-282,
-269,
-256,
-244,
-232,
-221,
-210,
-200,
-190,
-180,
-171,
-162,
-153,
-145,
-137,
-129,
-121,
-113,
-106,
-99,
-92,
-85,
-78,
-71,
-64,
-57,
-51,
-44,
-38,
-32,
-25,
-19,
-13,
-6,
0,
6,
13,
19,
25,
32,
38,
44,
51,
57,
64,
71,
78,
85,
92,
99,
106,
113,
121,
129,
137,
145,
153,
162,
171,
180,
190,
200,
210,
221,
232,
244,
256,
269,
282,
297,
312,
328,
345,
363,
383,
404,
427,
452,
479,
509,
541,
578,
618,
664,
715,
775,
844,
925,
1022,
1140,
1287,
1475,
1726,
2076,
2599,
3471,
5211,
10428,
32767,
-10428,
-5211,
-3471,
-2599,
-2076,
-1726,
-1475,
-1287,
-1140,
-1022,
-925,
-844,
-775,
-715,
-664,
-618,
-578,
-541,
-509,
-479,
-452,
-427,
-404,
-383,
-363,
-345,
-328,
-312,
-297,
-282,
-269,
-256,
-244,
-232,
-221,
-210,
-200,
-190,
-180,
-171,
-162,
-153,
-145,
-137,
-129,
-121,
-113,
-106,
-99,
-92,
-85,
-78,
-71,
-64,
-57,
-51,
-44,
-38,
-32,
-25,
-19,
-13,
-6};
// Squares of distance, in 16-shifted fixed point, for fast sqrt
long f16_sqrs[] = {
0,
256,
1024,
2304,
4096,
6400,
9216,
12544,
16384,
20736,
25600,
30976,
36864,
43264,
50176,
57600,
65536,
73984,
82944,
92416,
102400,
112896,
123904,
135424,
147456,
160000,
173056,
186624,
200704,
215296,
230400,
246016,
262144,
278784,
295936,
313600,
331776,
350464,
369664,
389376,
409600,
430336,
451584,
473344,
495616,
518400,
541696,
565504,
589824,
614656,
640000,
665856,
692224,
719104,
746496,
774400,
802816,
831744,
861184,
891136,
921600,
952576,
984064,
1016064,
1048576,
1081600,
1115136,
1149184,
1183744,
1218816,
1254400,
1290496,
1327104,
1364224,
1401856,
1440000,
1478656,
1517824,
1557504,
1597696,
1638400,
1679616,
1721344,
1763584,
1806336,
1849600,
1893376,
1937664,
1982464,
2027776,
2073600,
2119936,
2166784,
2214144,
2262016,
2310400,
2359296,
2408704,
2458624,
2509056,
2560000,
2611456,
2663424,
2715904,
2768896,
2822400,
2876416,
2930944,
2985984,
3041536,
3097600,
3154176,
3211264,
3268864,
3326976,
3385600,
3444736,
3504384,
3564544,
3625216,
3686400,
3748096,
3810304,
3873024,
3936256,
4000000,
4064256,
4129024,
4194304,
4260096,
4326400,
4393216,
4460544,
4528384,
4596736,
4665600,
4734976,
4804864,
4875264,
4946176,
5017600,
5089536,
5161984,
5234944,
5308416,
5382400,
5456896,
5531904,
5607424,
5683456,
5760000,
5837056,
5914624,
5992704,
6071296,
6150400,
6230016,
6310144,
6390784,
6471936,
6553600,
6635776,
6718464,
6801664,
6885376,
6969600,
7054336,
7139584,
7225344,
7311616,
7398400,
7485696,
7573504,
7661824,
7750656,
7840000,
7929856,
8020224,
8111104,
8202496,
8294400,
8386816,
8479744,
8573184,
8667136,
8761600,
8856576,
8952064,
9048064,
9144576,
9241600,
9339136,
9437184,
9535744,
9634816,
9734400,
9834496,
9935104,
10036224,
10137856,
10240000,
10342656,
10445824,
10549504,
10653696,
10758400,
10863616,
10969344,
11075584,
11182336,
11289600,
11397376,
11505664,
11614464,
11723776,
11833600,
11943936,
12054784,
12166144,
12278016,
12390400,
12503296,
12616704,
12730624,
12845056,
12960000,
13075456,
13191424,
13307904,
13424896,
13542400,
13660416,
13778944,
13897984,
14017536,
14137600,
14258176,
14379264,
14500864,
14622976,
14745600,
14868736,
14992384,
15116544,
15241216,
15366400,
15492096,
15618304,
15745024,
15872256,
16000000,
16128256,
16257024,
16386304,
16516096,
16646400,
16777216,
16908544,
17040384,
17172736,
17305600,
17438976,
17572864,
17707264,
17842176,
17977600,
18113536,
18249984,
18386944,
18524416,
18662400,
18800896,
18939904,
19079424,
19219456,
19360000,
19501056,
19642624,
19784704,
19927296,
20070400,
20214016,
20358144,
20502784,
20647936,
20793600,
20939776,
21086464,
21233664,
21381376,
21529600,
21678336,
21827584,
21977344,
22127616,
22278400,
22429696,
22581504,
22733824,
22886656,
23040000,
23193856,
23348224,
23503104,
23658496,
23814400,
23970816,
24127744,
24285184,
24443136,
24601600,
24760576,
24920064,
25080064,
25240576,
25401600,
25563136,
25725184,
25887744,
26050816,
26214400,
26378496,
26543104,
26708224,
26873856,
27040000,
27206656,
27373824,
27541504,
27709696,
27878400,
28047616,
28217344,
28387584,
28558336,
28729600,
28901376,
29073664,
29246464,
29419776,
29593600,
29767936,
29942784,
30118144,
30294016,
30470400,
30647296,
30824704,
31002624,
31181056,
31360000,
31539456,
31719424,
31899904,
32080896,
32262400,
32444416,
32626944,
32809984,
32993536,
33177600,
33362176,
33547264,
33732864,
33918976,
34105600,
34292736,
34480384,
34668544,
34857216,
35046400,
35236096,
35426304,
35617024,
35808256,
36000000,
36192256,
36385024,
36578304,
36772096,
36966400,
37161216,
37356544,
2147483647};
// Heights of given distance index
uchar draw_heigths[] = {
96,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
8,
15,
21,
26,
30,
34,
37,
40,
43,
45,
48,
50,
52,
53,
55,
56,
58,
59,
60,
61,
62,
63,
64,
65,
66,
67,
68,
68,
69,
70,
70,
71,
71,
72,
72,
73,
73,
74,
74,
75,
75,
75,
76,
76,
76,
77,
77,
77,
78,
78,
78,
78,
79,
79,
79,
79,
80,
80,
80,
80,
81,
81,
81,
81,
81,
81,
82,
82,
82,
82,
82,
82,
83,
83,
83,
83,
83,
83,
83,
84,
84,
84,
84,
84,
84,
84,
84,
84,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
86,
86,
86,
86,
86,
86,
86,
86,
86,
86,
86,
86,
86,
87,
87,
87,
87,
87,
87,
87,
87,
87,
87,
87,
87,
87,
87,
87,
87,
88,
88,
88,
88,
88,
88,
88,
88,
88,
88,
88,
88,
88,
88,
88,
88,
88,
88,
88,
88,
88,
88,
89,
89,
89,
89,
89,
89,
89,
89,
89,
89,
89,
89,
89,
89,
89,
89,
89,
89,
89,
89,
89,
89,
89,
89,
89,
89,
89,
89,
89,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
90,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
91,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92,
92};
// Heights of given distance index
uchar draw_heigths1[] = {
96,
191,
191,
191,
191,
191,
191,
191,
191,
191,
191,
191,
191,
191,
191,
191,
191,
191,
186,
181,
177,
173,
170,
167,
164,
161,
159,
156,
154,
152,
150,
149,
147,
145,
144,
143,
141,
140,
139,
138,
137,
136,
135,
134,
133,
133,
132,
131,
130,
130,
129,
128,
128,
127,
127,
126,
126,
125,
125,
124,
124,
123,
123,
122,
122,
122,
121,
121,
121,
120,
120,
120,
119,
119,
119,
118,
118,
118,
118,
117,
117,
117,
117,
116,
116,
116,
116,
115,
115,
115,
115,
115,
114,
114,
114,
114,
114,
113,
113,
113,
113,
113,
113,
113,
112,
112,
112,
112,
112,
112,
112,
111,
111,
111,
111,
111,
111,
111,
111,
110,
110,
110,
110,
110,
110,
110,
110,
110,
110,
109,
109,
109,
109,
109,
109,
109,
109,
109,
109,
109,
108,
108,
108,
108,
108,
108,
108,
108,
108,
108,
108,
108,
108,
107,
107,
107,
107,
107,
107,
107,
107,
107,
107,
107,
107,
107,
107,
107,
107,
106,
106,
106,
106,
106,
106,
106,
106,
106,
106,
106,
106,
106,
106,
106,
106,
106,
106,
106,
106,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
104,
104,
104,
104,
104,
104,
104,
104,
104,
104,
104,
104,
104,
104,
104,
104,
104,
104,
104,
104,
104,
104,
104,
104,
104,
104,
104,
104,
104,
104,
104,
104,
104,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
103,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
101,
101,
101,
101,
101,
101,
101,
101,
101,
101,
101,
101,
101,
101,
101,
101,
101,
101,
101,
101,
101,
101,
101,
101,
101,
101,
101,
101};
// Color intensities of given distance index
uchar draw_intens[] = {
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
1,
2,
2,
2,
2,
3,
3,
3,
3,
3,
4,
4,
4,
4,
4,
5,
5,
5,
5,
5,
5,
6,
6,
6,
6,
6,
6,
6,
6,
7,
7,
7,
7,
7,
7,
7,
7,
7,
8,
8,
8,
8,
8,
8,
8,
8,
8,
8,
8,
8,
9,
9,
9,
9,
9,
9,
9,
9,
9,
9,
9,
9,
9,
9,
9,
10,
10,
10,
10,
10,
10,
10,
10,
10,
10,
10,
10,
10,
10,
10,
10,
10,
10,
10,
10,
10,
11,
11,
11,
11,
11,
11,
11,
11,
11,
11,
11,
11,
11,
11,
11,
11,
11,
11,
11,
11,
11,
11,
11,
11,
11,
11,
11,
11,
11,
11,
11,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
12,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
13,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14,
14};
