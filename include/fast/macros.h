#ifndef FAST_MACROS_H
#define FAST_MACROS_H

#define FAST_MAKE_NVP(X) arc.add(#X, &X);

#define FAST_MACRO_EXPAND_ARGS1(a1) arc.add(#a1, &a1);
#define FAST_MACRO_EXPAND_ARGS2(a1, a2) \
  arc.add(#a1, &a1);                    \
  arc.add(#a2, &a2);
#define FAST_MACRO_EXPAND_ARGS3(a1, a2, a3) \
  arc.add(#a1, &a1);                        \
  arc.add(#a2, &a2);                        \
  arc.add(#a3, &a3);
#define FAST_MACRO_EXPAND_ARGS4(a1, a2, a3, a4) \
  arc.add(#a1, &a1);                            \
  arc.add(#a2, &a2);                            \
  arc.add(#a3, &a3);                            \
  arc.add(#a4, &a4);
#define FAST_MACRO_EXPAND_ARGS5(a1, a2, a3, a4, a5) \
  arc.add(#a1, &a1);                                \
  arc.add(#a2, &a2);                                \
  arc.add(#a3, &a3);                                \
  arc.add(#a4, &a4);                                \
  arc.add(#a5, &a5);

#define FAST_MACRO_EXPAND_ARGS6(a1, a2, a3, a4, a5, a6) \
  arc.add(#a1, &a1);                                    \
  arc.add(#a2, &a2);                                    \
  arc.add(#a3, &a3);                                    \
  arc.add(#a4, &a4);                                    \
  arc.add(#a5, &a5);                                    \
  arc.add(#a6, &a6);

#define FAST_MACRO_EXPAND_ARGS7(a1, a2, a3, a4, a5, a6, a7) \
  arc.add(#a1, &a1);                                        \
  arc.add(#a2, &a2);                                        \
  arc.add(#a3, &a3);                                        \
  arc.add(#a4, &a4);                                        \
  arc.add(#a5, &a5);                                        \
  arc.add(#a6, &a6);                                        \
  arc.add(#a7, &a7);

#define FAST_MACRO_EXPAND_ARGS8(a1, a2, a3, a4, a5, a6, a7, a8) \
  arc.add(#a1, &a1);                                            \
  arc.add(#a2, &a2);                                            \
  arc.add(#a3, &a3);                                            \
  arc.add(#a4, &a4);                                            \
  arc.add(#a5, &a5);                                            \
  arc.add(#a6, &a6);                                            \
  arc.add(#a7, &a7);                                            \
  arc.add(#a8, &a8);

#define FAST_MACRO_EXPAND_ARGS9(a1, a2, a3, a4, a5, a6, a7, a8, a9) \
  arc.add(#a1, &a1);                                                \
  arc.add(#a2, &a2);                                                \
  arc.add(#a3, &a3);                                                \
  arc.add(#a4, &a4);                                                \
  arc.add(#a5, &a5);                                                \
  arc.add(#a6, &a6);                                                \
  arc.add(#a7, &a7);                                                \
  arc.add(#a8, &a8);                                                \
  arc.add(#a9, &a9);

#define FAST_MACRO_EXPAND_ARGS10(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) \
  arc.add(#a1, &a1);                                                      \
  arc.add(#a2, &a2);                                                      \
  arc.add(#a3, &a3);                                                      \
  arc.add(#a4, &a4);                                                      \
  arc.add(#a5, &a5);                                                      \
  arc.add(#a6, &a6);                                                      \
  arc.add(#a7, &a7);                                                      \
  arc.add(#a8, &a8);                                                      \
  arc.add(#a9, &a9);                                                      \
  arc.add(#a10, &a10);

#define FAST_MACRO_EXPAND_ARGS11(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11) \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);

#define FAST_MACRO_EXPAND_ARGS12(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                                 a12)                                          \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);

#define FAST_MACRO_EXPAND_ARGS13(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                                 a12, a13)                                     \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);

#define FAST_MACRO_EXPAND_ARGS14(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                                 a12, a13, a14)                                \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);                                                         \
  arc.add(#a14, &a14);

#define FAST_MACRO_EXPAND_ARGS15(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                                 a12, a13, a14, a15)                           \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);                                                         \
  arc.add(#a14, &a14);                                                         \
  arc.add(#a15, &a15);

#define FAST_MACRO_EXPAND_ARGS16(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                                 a12, a13, a14, a15, a16)                      \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);                                                         \
  arc.add(#a14, &a14);                                                         \
  arc.add(#a15, &a15);                                                         \
  arc.add(#a16, &a16);

#define FAST_MACRO_EXPAND_ARGS17(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                                 a12, a13, a14, a15, a16, a17)                 \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);                                                         \
  arc.add(#a14, &a14);                                                         \
  arc.add(#a15, &a15);                                                         \
  arc.add(#a16, &a16);                                                         \
  arc.add(#a17, &a17);

#define FAST_MACRO_EXPAND_ARGS18(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                                 a12, a13, a14, a15, a16, a17, a18)            \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);                                                         \
  arc.add(#a14, &a14);                                                         \
  arc.add(#a15, &a15);                                                         \
  arc.add(#a16, &a16);                                                         \
  arc.add(#a17, &a17);                                                         \
  arc.add(#a18, &a18);

#define FAST_MACRO_EXPAND_ARGS19(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                                 a12, a13, a14, a15, a16, a17, a18, a19)       \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);                                                         \
  arc.add(#a14, &a14);                                                         \
  arc.add(#a15, &a15);                                                         \
  arc.add(#a16, &a16);                                                         \
  arc.add(#a17, &a17);                                                         \
  arc.add(#a18, &a18);                                                         \
  arc.add(#a19, &a19);

#define FAST_MACRO_EXPAND_ARGS20(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                                 a12, a13, a14, a15, a16, a17, a18, a19, a20)  \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);                                                         \
  arc.add(#a14, &a14);                                                         \
  arc.add(#a15, &a15);                                                         \
  arc.add(#a16, &a16);                                                         \
  arc.add(#a17, &a17);                                                         \
  arc.add(#a18, &a18);                                                         \
  arc.add(#a19, &a19);                                                         \
  arc.add(#a20, &a20);

#define FAST_MACRO_EXPAND_ARGS21(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                                 a12, a13, a14, a15, a16, a17, a18, a19, a20,  \
                                 a21)                                          \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);                                                         \
  arc.add(#a14, &a14);                                                         \
  arc.add(#a15, &a15);                                                         \
  arc.add(#a16, &a16);                                                         \
  arc.add(#a17, &a17);                                                         \
  arc.add(#a18, &a18);                                                         \
  arc.add(#a19, &a19);                                                         \
  arc.add(#a20, &a20);                                                         \
  arc.add(#a21, &a21);

#define FAST_MACRO_EXPAND_ARGS22(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                                 a12, a13, a14, a15, a16, a17, a18, a19, a20,  \
                                 a21, a22)                                     \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);                                                         \
  arc.add(#a14, &a14);                                                         \
  arc.add(#a15, &a15);                                                         \
  arc.add(#a16, &a16);                                                         \
  arc.add(#a17, &a17);                                                         \
  arc.add(#a18, &a18);                                                         \
  arc.add(#a19, &a19);                                                         \
  arc.add(#a20, &a20);                                                         \
  arc.add(#a21, &a21);                                                         \
  arc.add(#a22, &a22);

#define FAST_MACRO_EXPAND_ARGS23(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                                 a12, a13, a14, a15, a16, a17, a18, a19, a20,  \
                                 a21, a22, a23)                                \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);                                                         \
  arc.add(#a14, &a14);                                                         \
  arc.add(#a15, &a15);                                                         \
  arc.add(#a16, &a16);                                                         \
  arc.add(#a17, &a17);                                                         \
  arc.add(#a18, &a18);                                                         \
  arc.add(#a19, &a19);                                                         \
  arc.add(#a20, &a20);                                                         \
  arc.add(#a21, &a21);                                                         \
  arc.add(#a22, &a22);                                                         \
  arc.add(#a23, &a23);

#define FAST_MACRO_EXPAND_ARGS24(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                                 a12, a13, a14, a15, a16, a17, a18, a19, a20,  \
                                 a21, a22, a23, a24)                           \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);                                                         \
  arc.add(#a14, &a14);                                                         \
  arc.add(#a15, &a15);                                                         \
  arc.add(#a16, &a16);                                                         \
  arc.add(#a17, &a17);                                                         \
  arc.add(#a18, &a18);                                                         \
  arc.add(#a19, &a19);                                                         \
  arc.add(#a20, &a20);                                                         \
  arc.add(#a21, &a21);                                                         \
  arc.add(#a22, &a22);                                                         \
  arc.add(#a23, &a23);                                                         \
  arc.add(#a24, &a24);

#define FAST_MACRO_EXPAND_ARGS25(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                                 a12, a13, a14, a15, a16, a17, a18, a19, a20,  \
                                 a21, a22, a23, a24, a25)                      \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);                                                         \
  arc.add(#a14, &a14);                                                         \
  arc.add(#a15, &a15);                                                         \
  arc.add(#a16, &a16);                                                         \
  arc.add(#a17, &a17);                                                         \
  arc.add(#a18, &a18);                                                         \
  arc.add(#a19, &a19);                                                         \
  arc.add(#a20, &a20);                                                         \
  arc.add(#a21, &a21);                                                         \
  arc.add(#a22, &a22);                                                         \
  arc.add(#a23, &a23);                                                         \
  arc.add(#a24, &a24);                                                         \
  arc.add(#a25, &a25);

#define FAST_MACRO_EXPAND_ARGS26(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                                 a12, a13, a14, a15, a16, a17, a18, a19, a20,  \
                                 a21, a22, a23, a24, a25, a26)                 \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);                                                         \
  arc.add(#a14, &a14);                                                         \
  arc.add(#a15, &a15);                                                         \
  arc.add(#a16, &a16);                                                         \
  arc.add(#a17, &a17);                                                         \
  arc.add(#a18, &a18);                                                         \
  arc.add(#a19, &a19);                                                         \
  arc.add(#a20, &a20);                                                         \
  arc.add(#a21, &a21);                                                         \
  arc.add(#a22, &a22);                                                         \
  arc.add(#a23, &a23);                                                         \
  arc.add(#a24, &a24);                                                         \
  arc.add(#a25, &a25);                                                         \
  arc.add(#a26, &a26);

#define FAST_MACRO_EXPAND_ARGS27(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                                 a12, a13, a14, a15, a16, a17, a18, a19, a20,  \
                                 a21, a22, a23, a24, a25, a26, a27)            \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);                                                         \
  arc.add(#a14, &a14);                                                         \
  arc.add(#a15, &a15);                                                         \
  arc.add(#a16, &a16);                                                         \
  arc.add(#a17, &a17);                                                         \
  arc.add(#a18, &a18);                                                         \
  arc.add(#a19, &a19);                                                         \
  arc.add(#a20, &a20);                                                         \
  arc.add(#a21, &a21);                                                         \
  arc.add(#a22, &a22);                                                         \
  arc.add(#a23, &a23);                                                         \
  arc.add(#a24, &a24);                                                         \
  arc.add(#a25, &a25);                                                         \
  arc.add(#a26, &a26);                                                         \
  arc.add(#a27, &a27);

#define FAST_MACRO_EXPAND_ARGS28(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                                 a12, a13, a14, a15, a16, a17, a18, a19, a20,  \
                                 a21, a22, a23, a24, a25, a26, a27, a28)       \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);                                                         \
  arc.add(#a14, &a14);                                                         \
  arc.add(#a15, &a15);                                                         \
  arc.add(#a16, &a16);                                                         \
  arc.add(#a17, &a17);                                                         \
  arc.add(#a18, &a18);                                                         \
  arc.add(#a19, &a19);                                                         \
  arc.add(#a20, &a20);                                                         \
  arc.add(#a21, &a21);                                                         \
  arc.add(#a22, &a22);                                                         \
  arc.add(#a23, &a23);                                                         \
  arc.add(#a24, &a24);                                                         \
  arc.add(#a25, &a25);                                                         \
  arc.add(#a26, &a26);                                                         \
  arc.add(#a27, &a27);                                                         \
  arc.add(#a28, &a28);

#define FAST_MACRO_EXPAND_ARGS29(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                                 a12, a13, a14, a15, a16, a17, a18, a19, a20,  \
                                 a21, a22, a23, a24, a25, a26, a27, a28, a29)  \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);                                                         \
  arc.add(#a14, &a14);                                                         \
  arc.add(#a15, &a15);                                                         \
  arc.add(#a16, &a16);                                                         \
  arc.add(#a17, &a17);                                                         \
  arc.add(#a18, &a18);                                                         \
  arc.add(#a19, &a19);                                                         \
  arc.add(#a20, &a20);                                                         \
  arc.add(#a21, &a21);                                                         \
  arc.add(#a22, &a22);                                                         \
  arc.add(#a23, &a23);                                                         \
  arc.add(#a24, &a24);                                                         \
  arc.add(#a25, &a25);                                                         \
  arc.add(#a26, &a26);                                                         \
  arc.add(#a27, &a27);                                                         \
  arc.add(#a28, &a28);                                                         \
  arc.add(#a29, &a29);

#define FAST_MACRO_EXPAND_ARGS30(                                          \
    a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, \
    a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30)  \
  arc.add(#a1, &a1);                                                       \
  arc.add(#a2, &a2);                                                       \
  arc.add(#a3, &a3);                                                       \
  arc.add(#a4, &a4);                                                       \
  arc.add(#a5, &a5);                                                       \
  arc.add(#a6, &a6);                                                       \
  arc.add(#a7, &a7);                                                       \
  arc.add(#a8, &a8);                                                       \
  arc.add(#a9, &a9);                                                       \
  arc.add(#a10, &a10);                                                     \
  arc.add(#a11, &a11);                                                     \
  arc.add(#a12, &a12);                                                     \
  arc.add(#a13, &a13);                                                     \
  arc.add(#a14, &a14);                                                     \
  arc.add(#a15, &a15);                                                     \
  arc.add(#a16, &a16);                                                     \
  arc.add(#a17, &a17);                                                     \
  arc.add(#a18, &a18);                                                     \
  arc.add(#a19, &a19);                                                     \
  arc.add(#a20, &a20);                                                     \
  arc.add(#a21, &a21);                                                     \
  arc.add(#a22, &a22);                                                     \
  arc.add(#a23, &a23);                                                     \
  arc.add(#a24, &a24);                                                     \
  arc.add(#a25, &a25);                                                     \
  arc.add(#a26, &a26);                                                     \
  arc.add(#a27, &a27);                                                     \
  arc.add(#a28, &a28);                                                     \
  arc.add(#a29, &a29);                                                     \
  arc.add(#a30, &a30);

#define FAST_MACRO_EXPAND_ARGS31(                                              \
    a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16,     \
    a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31) \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);                                                         \
  arc.add(#a14, &a14);                                                         \
  arc.add(#a15, &a15);                                                         \
  arc.add(#a16, &a16);                                                         \
  arc.add(#a17, &a17);                                                         \
  arc.add(#a18, &a18);                                                         \
  arc.add(#a19, &a19);                                                         \
  arc.add(#a20, &a20);                                                         \
  arc.add(#a21, &a21);                                                         \
  arc.add(#a22, &a22);                                                         \
  arc.add(#a23, &a23);                                                         \
  arc.add(#a24, &a24);                                                         \
  arc.add(#a25, &a25);                                                         \
  arc.add(#a26, &a26);                                                         \
  arc.add(#a27, &a27);                                                         \
  arc.add(#a28, &a28);                                                         \
  arc.add(#a29, &a29);                                                         \
  arc.add(#a30, &a30);                                                         \
  arc.add(#a31, &a31);

#define FAST_MACRO_EXPAND_ARGS32(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                                 a12, a13, a14, a15, a16, a17, a18, a19, a20,  \
                                 a21, a22, a23, a24, a25, a26, a27, a28, a29,  \
                                 a30, a31, a32)                                \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);                                                         \
  arc.add(#a14, &a14);                                                         \
  arc.add(#a15, &a15);                                                         \
  arc.add(#a16, &a16);                                                         \
  arc.add(#a17, &a17);                                                         \
  arc.add(#a18, &a18);                                                         \
  arc.add(#a19, &a19);                                                         \
  arc.add(#a20, &a20);                                                         \
  arc.add(#a21, &a21);                                                         \
  arc.add(#a22, &a22);                                                         \
  arc.add(#a23, &a23);                                                         \
  arc.add(#a24, &a24);                                                         \
  arc.add(#a25, &a25);                                                         \
  arc.add(#a26, &a26);                                                         \
  arc.add(#a27, &a27);                                                         \
  arc.add(#a28, &a28);                                                         \
  arc.add(#a29, &a29);                                                         \
  arc.add(#a30, &a30);                                                         \
  arc.add(#a31, &a31);                                                         \
  arc.add(#a32, &a32);

#define FAST_MACRO_EXPAND_ARGS33(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                                 a12, a13, a14, a15, a16, a17, a18, a19, a20,  \
                                 a21, a22, a23, a24, a25, a26, a27, a28, a29,  \
                                 a30, a31, a32, a33)                           \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);                                                         \
  arc.add(#a14, &a14);                                                         \
  arc.add(#a15, &a15);                                                         \
  arc.add(#a16, &a16);                                                         \
  arc.add(#a17, &a17);                                                         \
  arc.add(#a18, &a18);                                                         \
  arc.add(#a19, &a19);                                                         \
  arc.add(#a20, &a20);                                                         \
  arc.add(#a21, &a21);                                                         \
  arc.add(#a22, &a22);                                                         \
  arc.add(#a23, &a23);                                                         \
  arc.add(#a24, &a24);                                                         \
  arc.add(#a25, &a25);                                                         \
  arc.add(#a26, &a26);                                                         \
  arc.add(#a27, &a27);                                                         \
  arc.add(#a28, &a28);                                                         \
  arc.add(#a29, &a29);                                                         \
  arc.add(#a30, &a30);                                                         \
  arc.add(#a31, &a31);                                                         \
  arc.add(#a32, &a32);                                                         \
  arc.add(#a33, &a33);

#define FAST_MACRO_EXPAND_ARGS34(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                                 a12, a13, a14, a15, a16, a17, a18, a19, a20,  \
                                 a21, a22, a23, a24, a25, a26, a27, a28, a29,  \
                                 a30, a31, a32, a33, a34)                      \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);                                                         \
  arc.add(#a14, &a14);                                                         \
  arc.add(#a15, &a15);                                                         \
  arc.add(#a16, &a16);                                                         \
  arc.add(#a17, &a17);                                                         \
  arc.add(#a18, &a18);                                                         \
  arc.add(#a19, &a19);                                                         \
  arc.add(#a20, &a20);                                                         \
  arc.add(#a21, &a21);                                                         \
  arc.add(#a22, &a22);                                                         \
  arc.add(#a23, &a23);                                                         \
  arc.add(#a24, &a24);                                                         \
  arc.add(#a25, &a25);                                                         \
  arc.add(#a26, &a26);                                                         \
  arc.add(#a27, &a27);                                                         \
  arc.add(#a28, &a28);                                                         \
  arc.add(#a29, &a29);                                                         \
  arc.add(#a30, &a30);                                                         \
  arc.add(#a31, &a31);                                                         \
  arc.add(#a32, &a32);                                                         \
  arc.add(#a33, &a33);                                                         \
  arc.add(#a34, &a34);

#define FAST_MACRO_EXPAND_ARGS35(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                                 a12, a13, a14, a15, a16, a17, a18, a19, a20,  \
                                 a21, a22, a23, a24, a25, a26, a27, a28, a29,  \
                                 a30, a31, a32, a33, a34, a35)                 \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);                                                         \
  arc.add(#a14, &a14);                                                         \
  arc.add(#a15, &a15);                                                         \
  arc.add(#a16, &a16);                                                         \
  arc.add(#a17, &a17);                                                         \
  arc.add(#a18, &a18);                                                         \
  arc.add(#a19, &a19);                                                         \
  arc.add(#a20, &a20);                                                         \
  arc.add(#a21, &a21);                                                         \
  arc.add(#a22, &a22);                                                         \
  arc.add(#a23, &a23);                                                         \
  arc.add(#a24, &a24);                                                         \
  arc.add(#a25, &a25);                                                         \
  arc.add(#a26, &a26);                                                         \
  arc.add(#a27, &a27);                                                         \
  arc.add(#a28, &a28);                                                         \
  arc.add(#a29, &a29);                                                         \
  arc.add(#a30, &a30);                                                         \
  arc.add(#a31, &a31);                                                         \
  arc.add(#a32, &a32);                                                         \
  arc.add(#a33, &a33);                                                         \
  arc.add(#a34, &a34);                                                         \
  arc.add(#a35, &a35);

#define FAST_MACRO_EXPAND_ARGS36(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                                 a12, a13, a14, a15, a16, a17, a18, a19, a20,  \
                                 a21, a22, a23, a24, a25, a26, a27, a28, a29,  \
                                 a30, a31, a32, a33, a34, a35, a36)            \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);                                                         \
  arc.add(#a14, &a14);                                                         \
  arc.add(#a15, &a15);                                                         \
  arc.add(#a16, &a16);                                                         \
  arc.add(#a17, &a17);                                                         \
  arc.add(#a18, &a18);                                                         \
  arc.add(#a19, &a19);                                                         \
  arc.add(#a20, &a20);                                                         \
  arc.add(#a21, &a21);                                                         \
  arc.add(#a22, &a22);                                                         \
  arc.add(#a23, &a23);                                                         \
  arc.add(#a24, &a24);                                                         \
  arc.add(#a25, &a25);                                                         \
  arc.add(#a26, &a26);                                                         \
  arc.add(#a27, &a27);                                                         \
  arc.add(#a28, &a28);                                                         \
  arc.add(#a29, &a29);                                                         \
  arc.add(#a30, &a30);                                                         \
  arc.add(#a31, &a31);                                                         \
  arc.add(#a32, &a32);                                                         \
  arc.add(#a33, &a33);                                                         \
  arc.add(#a34, &a34);                                                         \
  arc.add(#a35, &a35);                                                         \
  arc.add(#a36, &a36);

#define FAST_MACRO_EXPAND_ARGS37(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                                 a12, a13, a14, a15, a16, a17, a18, a19, a20,  \
                                 a21, a22, a23, a24, a25, a26, a27, a28, a29,  \
                                 a30, a31, a32, a33, a34, a35, a36, a37)       \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);                                                         \
  arc.add(#a14, &a14);                                                         \
  arc.add(#a15, &a15);                                                         \
  arc.add(#a16, &a16);                                                         \
  arc.add(#a17, &a17);                                                         \
  arc.add(#a18, &a18);                                                         \
  arc.add(#a19, &a19);                                                         \
  arc.add(#a20, &a20);                                                         \
  arc.add(#a21, &a21);                                                         \
  arc.add(#a22, &a22);                                                         \
  arc.add(#a23, &a23);                                                         \
  arc.add(#a24, &a24);                                                         \
  arc.add(#a25, &a25);                                                         \
  arc.add(#a26, &a26);                                                         \
  arc.add(#a27, &a27);                                                         \
  arc.add(#a28, &a28);                                                         \
  arc.add(#a29, &a29);                                                         \
  arc.add(#a30, &a30);                                                         \
  arc.add(#a31, &a31);                                                         \
  arc.add(#a32, &a32);                                                         \
  arc.add(#a33, &a33);                                                         \
  arc.add(#a34, &a34);                                                         \
  arc.add(#a35, &a35);                                                         \
  arc.add(#a36, &a36);                                                         \
  arc.add(#a37, &a37);

#define FAST_MACRO_EXPAND_ARGS38(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
                                 a12, a13, a14, a15, a16, a17, a18, a19, a20,  \
                                 a21, a22, a23, a24, a25, a26, a27, a28, a29,  \
                                 a30, a31, a32, a33, a34, a35, a36, a37, a38)  \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);                                                         \
  arc.add(#a14, &a14);                                                         \
  arc.add(#a15, &a15);                                                         \
  arc.add(#a16, &a16);                                                         \
  arc.add(#a17, &a17);                                                         \
  arc.add(#a18, &a18);                                                         \
  arc.add(#a19, &a19);                                                         \
  arc.add(#a20, &a20);                                                         \
  arc.add(#a21, &a21);                                                         \
  arc.add(#a22, &a22);                                                         \
  arc.add(#a23, &a23);                                                         \
  arc.add(#a24, &a24);                                                         \
  arc.add(#a25, &a25);                                                         \
  arc.add(#a26, &a26);                                                         \
  arc.add(#a27, &a27);                                                         \
  arc.add(#a28, &a28);                                                         \
  arc.add(#a29, &a29);                                                         \
  arc.add(#a30, &a30);                                                         \
  arc.add(#a31, &a31);                                                         \
  arc.add(#a32, &a32);                                                         \
  arc.add(#a33, &a33);                                                         \
  arc.add(#a34, &a34);                                                         \
  arc.add(#a35, &a35);                                                         \
  arc.add(#a36, &a36);                                                         \
  arc.add(#a37, &a37);                                                         \
  arc.add(#a38, &a38);

#define FAST_MACRO_EXPAND_ARGS39(                                              \
    a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16,     \
    a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, \
    a32, a33, a34, a35, a36, a37, a38, a39)                                    \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);                                                         \
  arc.add(#a14, &a14);                                                         \
  arc.add(#a15, &a15);                                                         \
  arc.add(#a16, &a16);                                                         \
  arc.add(#a17, &a17);                                                         \
  arc.add(#a18, &a18);                                                         \
  arc.add(#a19, &a19);                                                         \
  arc.add(#a20, &a20);                                                         \
  arc.add(#a21, &a21);                                                         \
  arc.add(#a22, &a22);                                                         \
  arc.add(#a23, &a23);                                                         \
  arc.add(#a24, &a24);                                                         \
  arc.add(#a25, &a25);                                                         \
  arc.add(#a26, &a26);                                                         \
  arc.add(#a27, &a27);                                                         \
  arc.add(#a28, &a28);                                                         \
  arc.add(#a29, &a29);                                                         \
  arc.add(#a30, &a30);                                                         \
  arc.add(#a31, &a31);                                                         \
  arc.add(#a32, &a32);                                                         \
  arc.add(#a33, &a33);                                                         \
  arc.add(#a34, &a34);                                                         \
  arc.add(#a35, &a35);                                                         \
  arc.add(#a36, &a36);                                                         \
  arc.add(#a37, &a37);                                                         \
  arc.add(#a38, &a38);                                                         \
  arc.add(#a39, &a39);

#define FAST_MACRO_EXPAND_ARGS40(                                              \
    a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16,     \
    a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, \
    a32, a33, a34, a35, a36, a37, a38, a39, a40)                               \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);                                                         \
  arc.add(#a14, &a14);                                                         \
  arc.add(#a15, &a15);                                                         \
  arc.add(#a16, &a16);                                                         \
  arc.add(#a17, &a17);                                                         \
  arc.add(#a18, &a18);                                                         \
  arc.add(#a19, &a19);                                                         \
  arc.add(#a20, &a20);                                                         \
  arc.add(#a21, &a21);                                                         \
  arc.add(#a22, &a22);                                                         \
  arc.add(#a23, &a23);                                                         \
  arc.add(#a24, &a24);                                                         \
  arc.add(#a25, &a25);                                                         \
  arc.add(#a26, &a26);                                                         \
  arc.add(#a27, &a27);                                                         \
  arc.add(#a28, &a28);                                                         \
  arc.add(#a29, &a29);                                                         \
  arc.add(#a30, &a30);                                                         \
  arc.add(#a31, &a31);                                                         \
  arc.add(#a32, &a32);                                                         \
  arc.add(#a33, &a33);                                                         \
  arc.add(#a34, &a34);                                                         \
  arc.add(#a35, &a35);                                                         \
  arc.add(#a36, &a36);                                                         \
  arc.add(#a37, &a37);                                                         \
  arc.add(#a38, &a38);                                                         \
  arc.add(#a39, &a39);                                                         \
  arc.add(#a40, &a40);

#define FAST_MACRO_EXPAND_ARGS41(                                              \
    a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16,     \
    a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, \
    a32, a33, a34, a35, a36, a37, a38, a39, a40, a41)                          \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);                                                         \
  arc.add(#a14, &a14);                                                         \
  arc.add(#a15, &a15);                                                         \
  arc.add(#a16, &a16);                                                         \
  arc.add(#a17, &a17);                                                         \
  arc.add(#a18, &a18);                                                         \
  arc.add(#a19, &a19);                                                         \
  arc.add(#a20, &a20);                                                         \
  arc.add(#a21, &a21);                                                         \
  arc.add(#a22, &a22);                                                         \
  arc.add(#a23, &a23);                                                         \
  arc.add(#a24, &a24);                                                         \
  arc.add(#a25, &a25);                                                         \
  arc.add(#a26, &a26);                                                         \
  arc.add(#a27, &a27);                                                         \
  arc.add(#a28, &a28);                                                         \
  arc.add(#a29, &a29);                                                         \
  arc.add(#a30, &a30);                                                         \
  arc.add(#a31, &a31);                                                         \
  arc.add(#a32, &a32);                                                         \
  arc.add(#a33, &a33);                                                         \
  arc.add(#a34, &a34);                                                         \
  arc.add(#a35, &a35);                                                         \
  arc.add(#a36, &a36);                                                         \
  arc.add(#a37, &a37);                                                         \
  arc.add(#a38, &a38);                                                         \
  arc.add(#a39, &a39);                                                         \
  arc.add(#a40, &a40);                                                         \
  arc.add(#a41, &a41);

#define FAST_MACRO_EXPAND_ARGS42(                                              \
    a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16,     \
    a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, \
    a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42)                     \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);                                                         \
  arc.add(#a14, &a14);                                                         \
  arc.add(#a15, &a15);                                                         \
  arc.add(#a16, &a16);                                                         \
  arc.add(#a17, &a17);                                                         \
  arc.add(#a18, &a18);                                                         \
  arc.add(#a19, &a19);                                                         \
  arc.add(#a20, &a20);                                                         \
  arc.add(#a21, &a21);                                                         \
  arc.add(#a22, &a22);                                                         \
  arc.add(#a23, &a23);                                                         \
  arc.add(#a24, &a24);                                                         \
  arc.add(#a25, &a25);                                                         \
  arc.add(#a26, &a26);                                                         \
  arc.add(#a27, &a27);                                                         \
  arc.add(#a28, &a28);                                                         \
  arc.add(#a29, &a29);                                                         \
  arc.add(#a30, &a30);                                                         \
  arc.add(#a31, &a31);                                                         \
  arc.add(#a32, &a32);                                                         \
  arc.add(#a33, &a33);                                                         \
  arc.add(#a34, &a34);                                                         \
  arc.add(#a35, &a35);                                                         \
  arc.add(#a36, &a36);                                                         \
  arc.add(#a37, &a37);                                                         \
  arc.add(#a38, &a38);                                                         \
  arc.add(#a39, &a39);                                                         \
  arc.add(#a40, &a40);                                                         \
  arc.add(#a41, &a41);                                                         \
  arc.add(#a42, &a42);

#define FAST_MACRO_EXPAND_ARGS43(                                              \
    a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16,     \
    a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, \
    a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43)                \
  arc.add(#a1, &a1);                                                           \
  arc.add(#a2, &a2);                                                           \
  arc.add(#a3, &a3);                                                           \
  arc.add(#a4, &a4);                                                           \
  arc.add(#a5, &a5);                                                           \
  arc.add(#a6, &a6);                                                           \
  arc.add(#a7, &a7);                                                           \
  arc.add(#a8, &a8);                                                           \
  arc.add(#a9, &a9);                                                           \
  arc.add(#a10, &a10);                                                         \
  arc.add(#a11, &a11);                                                         \
  arc.add(#a12, &a12);                                                         \
  arc.add(#a13, &a13);                                                         \
  arc.add(#a14, &a14);                                                         \
  arc.add(#a15, &a15);                                                         \
  arc.add(#a16, &a16);                                                         \
  arc.add(#a17, &a17);                                                         \
  arc.add(#a18, &a18);                                                         \
  arc.add(#a19, &a19);                                                         \
  arc.add(#a20, &a20);                                                         \
  arc.add(#a21, &a21);                                                         \
  arc.add(#a22, &a22);                                                         \
  arc.add(#a23, &a23);                                                         \
  arc.add(#a24, &a24);                                                         \
  arc.add(#a25, &a25);                                                         \
  arc.add(#a26, &a26);                                                         \
  arc.add(#a27, &a27);                                                         \
  arc.add(#a28, &a28);                                                         \
  arc.add(#a29, &a29);                                                         \
  arc.add(#a30, &a30);                                                         \
  arc.add(#a31, &a31);                                                         \
  arc.add(#a32, &a32);                                                         \
  arc.add(#a33, &a33);                                                         \
  arc.add(#a34, &a34);                                                         \
  arc.add(#a35, &a35);                                                         \
  arc.add(#a36, &a36);                                                         \
  arc.add(#a37, &a37);                                                         \
  arc.add(#a38, &a38);                                                         \
  arc.add(#a39, &a39);                                                         \
  arc.add(#a40, &a40);                                                         \
  arc.add(#a41, &a41);                                                         \
  arc.add(#a42, &a42);                                                         \
  arc.add(#a43, &a43);

// Helper macro to select the right expansion based on the number of arguments
#define GET_FAST_MACRO(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, \
                       _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24,  \
                       _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35,  \
                       _36, _37, _38, _39, _40, _41, _42, _43, NAME, ...)      \
  NAME

// Main macro for FAST_LOAD_METADATA
#define FAST_LOAD_METADATA(...)                                        \
  void load_metadata(fast::Archive& arc) {                             \
    GET_FAST_MACRO(__VA_ARGS__, FAST_MACRO_EXPAND_ARGS43,              \
                   FAST_MACRO_EXPAND_ARGS42, FAST_MACRO_EXPAND_ARGS41, \
                   FAST_MACRO_EXPAND_ARGS40, FAST_MACRO_EXPAND_ARGS39, \
                   FAST_MACRO_EXPAND_ARGS38, FAST_MACRO_EXPAND_ARGS37, \
                   FAST_MACRO_EXPAND_ARGS36, FAST_MACRO_EXPAND_ARGS35, \
                   FAST_MACRO_EXPAND_ARGS34, FAST_MACRO_EXPAND_ARGS33, \
                   FAST_MACRO_EXPAND_ARGS32, FAST_MACRO_EXPAND_ARGS31, \
                   FAST_MACRO_EXPAND_ARGS30, FAST_MACRO_EXPAND_ARGS29, \
                   FAST_MACRO_EXPAND_ARGS28, FAST_MACRO_EXPAND_ARGS27, \
                   FAST_MACRO_EXPAND_ARGS26, FAST_MACRO_EXPAND_ARGS25, \
                   FAST_MACRO_EXPAND_ARGS24, FAST_MACRO_EXPAND_ARGS23, \
                   FAST_MACRO_EXPAND_ARGS22, FAST_MACRO_EXPAND_ARGS21, \
                   FAST_MACRO_EXPAND_ARGS20, FAST_MACRO_EXPAND_ARGS19, \
                   FAST_MACRO_EXPAND_ARGS18, FAST_MACRO_EXPAND_ARGS17, \
                   FAST_MACRO_EXPAND_ARGS16, FAST_MACRO_EXPAND_ARGS15, \
                   FAST_MACRO_EXPAND_ARGS14, FAST_MACRO_EXPAND_ARGS13, \
                   FAST_MACRO_EXPAND_ARGS12, FAST_MACRO_EXPAND_ARGS11, \
                   FAST_MACRO_EXPAND_ARGS10, FAST_MACRO_EXPAND_ARGS9,  \
                   FAST_MACRO_EXPAND_ARGS8, FAST_MACRO_EXPAND_ARGS7,   \
                   FAST_MACRO_EXPAND_ARGS6, FAST_MACRO_EXPAND_ARGS5,   \
                   FAST_MACRO_EXPAND_ARGS4, FAST_MACRO_EXPAND_ARGS3,   \
                   FAST_MACRO_EXPAND_ARGS2, FAST_MACRO_EXPAND_ARGS1)   \
    (__VA_ARGS__);                                                     \
  }

#endif  // FAST_MACROS_H
