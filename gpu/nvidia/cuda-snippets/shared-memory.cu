__global__ void sharedExample(float* g_data) {
    // 1. Declaration (Static Allocation)
    __shared__ float s_data[256];

    int tid = threadIdx.x;

    // 2. Load from Global to Shared
    s_data[tid] = g_data[tid];

    // 3. Barrier Synchronization
    // Essential: ensures all threads in the block have finished step 2
    __syncthreads();

    // 4. Compute using Shared Memory (Fast!)
    float val = s_data[tid] * 2.0f;

    // 5. Write back to Global
    g_data[tid] = val;
}


// Column access with padding
__shared__ float tile[32][33];
int tid = threadIdx.x;

// Stride is now 33 instead of 32
// GCD(33, 32) = 1 (No Conflicts)
float val = tile[tid][0]; 


__global__ void optimized_transpose(float *out, float *in) {
    // +1 Padding prevents 32-way bank conflicts!
    __shared__ float tile[32][33]; 
    
    int x = threadIdx.x;
    int y = threadIdx.y;
    
    // Write row-wise (Stride 1 - Fast)
    tile[y][x] = in[...]; 
    __syncthreads();
    
    // Read col-wise (Stride 33 instead of 32)
    // t0->Bank0, t1->Bank1, t2->Bank2... No conflicts!
    out[...] = tile[x][y];
}