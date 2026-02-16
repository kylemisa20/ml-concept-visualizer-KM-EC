// Brief: Reference implementation of GEMM loop orders and tiling for
// comparison.
#include <vector>

using Matrix = std::vector<std::vector<double>>;
int N = 4;
int T = 2;

void gemm_ijk(const Matrix& A, const Matrix& B, Matrix& C) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      C[i][j] = 0.0;
      for (int k = 0; k < N; ++k) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

void gemm_kij(const Matrix& A, const Matrix& B, Matrix& C) {
  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

void gemm_jki(const Matrix& A, const Matrix& B, Matrix& C) {
  for (int j = 0; j < N; ++j) {
    for (int k = 0; k < N; ++k) {
      for (int i = 0; i < N; ++i) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

void gemm_ijk_bt(const Matrix& A, const Matrix& BT, Matrix& C) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      C[i][j] = 0.0;
      for (int k = 0; k < N; ++k) {
        C[i][j] += A[i][k] * BT[j][k];
      }
    }
  }
}

void gemm_blocked(const Matrix& A, const Matrix& B, Matrix& C) {
  // Three outer loops iterate over tiles
  // Note that the stride is T.
  for (int i = 0; i < N; i += T) {
    for (int j = 0; j < N; j += T) {
      for (int k = 0; k < N; k += T) {
        // three inner loops iterate within tiles
        for (int il = i; il < i + T; ++il) {
          for (int jl = j; jl < j + T; ++jl) {
            for (int kl = k; kl < k + T; ++kl) {
              C[il][jl] += A[il][kl] * B[kl][jl];
            }
          }
        }
      }
    }
  }
}
