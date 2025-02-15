#include<vector>
typedef std::vector< std::vector< int > >Matrix;
const Matrix d_10_01 = {
{0, 0, 6, 0, 0, 3, 4, 0, 10, 0},
{2, 6, 4, 0, 0, 0, 0, 0, 9, 0 },
{0, 2, 10, 0, 0, 0, 0, 0, 5, 9},
{10, 1, 5, 4, 2, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 1, 9, 8, 4, 0, 0 },
{0, 0, 3, 2, 9, 0, 0, 1, 0, 0 },
{6, 0, 0, 0, 0, 7, 0, 10, 0, 5},
{0, 0, 0, 0, 0, 8, 6, 5, 0, 7 },
{1, 3, 0, 6, 0, 0, 5, 0, 0, 2 },
{0, 5, 0, 9, 6, 2, 0, 0, 8, 0 }
};

const Matrix d_10_06 = {
{1, 0, 0, 0, 5, 0, 2, 6, 4, 0 },
{9, 0, 1, 2, 0, 0, 0, 0, 0, 7 },
{0, 0, 7, 5, 9, 1, 0, 0, 0, 0 },
{0, 0, 0, 0, 7, 4, 0, 1, 5, 0 },
{0, 2, 9, 0, 0, 0, 0, 3, 0, 5 },
{0, 4, 6, 3, 0, 0, 0, 0, 8, 0 },
{0, 0, 4, 7, 6, 0, 3, 0, 0, 0 },
{5, 1, 0, 4, 0, 0, 0, 0, 0, 8 },
{0, 6, 0, 0, 0, 7, 8, 5, 0, 4 },
{7, 9, 0, 0, 0, 8, 1, 0, 3, 0 }
};

const Matrix d_10_07 = {
{0, 8, 0, 0, 6, 10, 0, 0, 5, 0},
{9, 0, 3, 8, 2, 0, 0, 0, 0, 0 },
{0, 3, 1, 0, 0, 0, 6, 9 ,0, 8 },
{10, 1, 0, 6, 0, 0, 8, 0, 0, 0},
{0, 0, 2 ,0, 0, 3, 0, 6, 0, 1 },
{0, 0, 0 ,0, 0, 9, 4 ,7, 8, 0 },
{8, 0 ,0, 7 ,9, 1, 0, 0, 2, 0 },
{0, 0 ,0 ,0 ,1, 0, 3, 5, 7, 2 },
{4, 10, 0, 9, 0, 0, 0, 1, 0, 0},
{0, 7, 5, 0, 0, 6, 0, 0 ,0, 4 }
};

const Matrix d_10_08 = {
{2, 9, 3, 0, 0, 6, 0, 4, 0, 0 },
{0, 0, 0, 0, 10, 4, 1, 0, 7, 0},
{4, 0, 8, 6, 0, 10, 0, 0, 0, 0},
{0, 7, 0, 0, 5, 1, 4, 0, 9, 0 },
{0, 0, 1, 0, 0, 2, 7, 0, 0, 3 },
{0, 0, 0, 0, 1, 0, 9, 6, 8, 0 },
{0, 0, 7, 1, 0, 0, 0, 9, 0, 4 },
{1, 4, 2, 9, 0, 0, 0, 0, 0, 0 },
{10, 8, 0, 0, 4, 0, 0, 0, 3, 1},
{0, 10, 0, 4, 0, 0, 0, 1, 0, 8}
};

const Matrix d_10_09 = {
{1, 0, 0, 5, 0, 0, 10, 6, 0, 8},
{0, 3, 5, 0, 7, 0, 0, 8, 0, 0 },
{0, 8, 2, 0, 0, 3, 0, 10, 0, 0},
{0, 2, 3, 0, 10, 0, 0, 0, 0, 6},
{3, 0, 0, 9, 1, 0, 0, 0, 10, 5},
{10, 5, 8, 0, 0, 0, 0, 0, 3, 7},
{0, 0, 0, 3, 8, 0, 0, 5, 0, 10},
{0, 10, 0, 2, 0, 5, 1, 0, 0, 0},
{0, 0, 0, 0, 5, 10, 3, 0, 6, 0},
{2, 0, 0, 0 ,0, 6, 5, 0, 7, 0 }
};

const Matrix d_15_01 = {
{0, 6, 8, 0, 0, 0, 0, 0, 13, 1, 4, 10, 5, 12, 0  },
{15, 11, 13, 12, 0, 0, 0, 2, 0, 3, 0, 0, 0, 0, 4 },
{0, 0, 10, 13, 0, 6, 1, 11, 0, 0, 0, 14, 2, 7, 0 },
{0, 0, 0, 4, 13, 0, 12, 0, 11, 9, 10, 1, 0, 0, 7 },
{0, 0, 11, 6, 1, 14, 0, 10, 4, 0, 12, 9, 0, 0, 0 },
{0, 4, 0, 0, 12, 11, 7, 0, 14, 0, 6, 3, 0, 0, 1  },
{1, 9, 12, 10, 8, 13, 0, 0, 0, 0, 0, 11, 0, 0 ,6 },
{14, 13, 5, 8, 0, 10, 0, 0, 0, 0, 7, 0, 1, 9, 0  },
{0, 5, 0, 0, 0, 7, 6, 0, 15, 10, 8, 0, 0, 1, 2   },
{2, 0, 4, 5, 14, 0, 0, 7, 6, 0, 0, 15, 13, 0, 0  },
{11, 0, 0, 0, 0, 12, 8, 9, 0, 0, 2, 6, 0, 13, 10 },
{0, 0, 0, 0, 11, 0, 10, 1, 7, 6, 0, 0, 12, 4, 13 },
{13, 12, 0, 11, 5, 0, 15, 6, 0, 7, 0, 0,10, 0, 0 },
{6, 0, 7, 0, 0, 8, 0, 12, 0, 14, 13, 0, 15, 0, 5 },
{10, 7, 0, 0, 15, 0, 4, 0, 12, 5, 0, 0, 6, 2, 0  }
};

const Matrix d_30_01 = {
{0, 19, 0, 29, 0, 15, 0, 25, 0, 4, 7, 21, 0, 14, 0, 24, 22, 0, 0, 0, 5, 23, 10, 26, 0, 16, 9, 2, 0, 8   },
{0, 18, 0, 5, 29, 22, 0, 17, 0, 7, 30, 6, 21, 0, 24, 0, 26, 1, 13, 11, 23, 0, 15, 14, 19, 0, 0, 0, 0, 0 },
{15, 0, 30, 0, 4, 6, 19, 0, 0, 14, 0, 0, 0, 0, 10, 27, 0, 0, 12, 20, 25, 18, 22, 0, 13, 7, 0, 0, 29, 17 },
{0, 0, 20, 0, 9, 17, 6, 0, 16, 0, 23, 18, 12, 0, 13, 0, 0, 11, 26, 0, 29, 0, 0, 0, 2, 19, 15, 7, 3, 0   },
{0, 0, 4, 3, 0, 25, 0, 0, 0, 0, 22, 8, 0, 0, 20, 14, 24, 6, 0, 29, 30, 7, 0, 27, 12, 0, 0, 5, 19, 23    },
{0, 0, 0, 0, 17, 12, 0, 24, 15, 16, 4, 20, 14, 0, 0, 0, 0, 18, 0, 0, 19, 2, 27, 30, 0, 6, 0, 26, 8, 29  },
{14, 12, 6, 23, 0, 0, 0, 4, 0, 2, 13, 24, 9, 0, 0, 3, 17, 30, 8, 0, 7, 0, 0, 0, 20, 18, 0, 11, 0, 5     },
{12, 0, 0, 7, 0, 1, 9, 30, 28, 25, 0, 14, 20, 0, 19, 22, 10, 0, 0, 26, 27, 0, 0, 11, 0, 5, 0, 0, 6, 24  },
{0, 0, 28, 0, 11, 0, 0, 7, 0, 0, 0, 27, 3, 17, 18, 21, 0, 14, 23, 24, 12, 0, 25, 9, 26, 22, 0, 0, 16, 2 },
{2, 3, 21, 0, 26, 0, 5, 1, 14, 0, 0, 17, 0, 6, 0, 23, 18, 10, 25, 28, 0, 15, 9, 16, 27, 0, 0, 0, 0, 0   },
{16, 28, 10, 0, 19, 11, 0, 0, 24, 0, 6, 0, 0, 29, 23, 30, 0, 21, 2, 3, 1, 22, 0, 5, 0, 13, 0, 0, 12, 0  },
{0, 15, 13, 0, 5, 0, 20, 0, 26, 27, 0, 7, 22, 1, 0, 4, 19, 0, 14, 10, 0, 0, 11, 0, 8, 24, 0, 0, 25, 0   },
{4, 0, 12, 21, 0, 23, 3, 0, 7, 17, 0, 0, 16, 5, 29, 9, 0, 0, 0, 27, 0, 0, 8, 10, 28, 1, 2, 14, 0, 0     },
{0, 0, 16, 0, 0, 21, 12, 19, 0, 26, 0, 13, 8, 22, 2, 0, 25, 5, 15, 0, 20, 0, 24, 0, 0, 0, 17, 6, 23, 0  },
{18, 2, 29, 0, 0, 9, 10, 28, 30, 0, 12, 22, 23, 0, 0, 0, 14, 0, 5, 0, 0, 20, 7, 0, 0, 15, 26, 0, 17, 0  },
{5, 24, 0, 6, 25, 0, 0, 0, 10, 19, 1, 0, 29, 2, 8, 0, 30, 20, 0, 12, 0, 28, 3, 0, 0, 0, 11, 27, 15, 0   },
{30, 8, 5, 0, 7, 0, 16, 14, 21, 3, 0, 0, 11, 9, 26, 29, 12, 13, 1, 0, 0, 0, 0, 4, 0, 0, 0, 22, 0, 0     },
{23, 0, 9, 27, 21, 0, 0, 20, 25, 28, 0, 0, 24, 0, 4, 17, 13, 0, 0, 0, 26, 0, 0, 18, 29, 2, 14, 0, 0, 22 },
{0, 0, 19, 28, 0, 0, 15, 21, 5, 0, 26, 29, 0, 20, 0, 0, 16, 0, 0, 1, 0, 12, 0, 0, 9, 8, 7, 17, 24, 30   },
{6, 0, 0, 0, 2, 24, 0, 0, 8, 0, 3, 15, 0, 0, 11, 20, 0, 0, 16, 9, 0, 27, 30, 17, 0, 14, 10, 1, 13, 4    },
{28, 14, 22, 30, 0, 3, 0, 0, 2, 0, 19, 0, 17, 10, 15, 0, 0, 29, 0, 23, 11, 0, 26, 0, 0, 20, 12, 0, 21, 1},
{0, 11, 0, 19, 24, 0, 30, 8, 0, 1, 0, 9, 0, 26, 0, 0, 0, 12, 3, 0, 0, 16, 18, 22, 21, 0, 25, 15, 20, 7  },
{13, 23, 15, 17, 0, 28, 21, 26, 0, 0, 11, 0, 2, 0, 27, 8, 0, 0, 9, 4, 0, 14, 12, 0, 10, 0, 0, 0, 0, 19  },
{0, 10, 11, 13, 0, 0, 0, 0, 0, 22, 24, 23, 26, 25, 12, 15, 1, 0, 7, 0, 8, 6, 0, 0, 16, 17, 18, 28, 0, 0 },
{29, 25, 0, 0, 12, 5, 8, 11, 0, 9, 10, 3, 0, 0, 0, 26, 7, 0, 0, 0, 14, 1, 0, 2, 15, 0, 6, 16, 0, 13     },
{21, 9, 0, 26, 15, 0, 25, 0, 22, 23, 0, 0, 0, 27, 0, 0, 0, 4, 18, 0, 0, 11, 13, 7, 5, 0, 3, 29, 0, 10   },
{10, 29, 0, 14, 0, 26, 4, 0, 9, 5, 0, 0, 15, 0, 6, 0, 11, 7, 24, 18, 0, 8, 0, 28, 0, 0, 19, 0, 2, 21    },
{26, 6, 0, 0, 22, 0, 0, 16, 19, 0, 18, 11, 0, 12, 21, 0, 3, 17, 0, 2, 13, 25, 0, 0, 23, 27, 0, 4, 0, 0  },
{0, 0, 0, 22, 0, 13, 1, 2, 29, 0, 15, 0, 19, 28, 0, 11, 4, 27, 0, 16, 21, 0, 6, 12, 0, 0, 20, 0, 0, 9   },
{0, 13, 24, 16, 30, 0, 14, 0, 0, 18, 0, 0, 0, 15, 0, 0, 0, 9, 10, 0, 3, 26, 2, 25, 0, 29, 5, 20, 11, 6  }
};
