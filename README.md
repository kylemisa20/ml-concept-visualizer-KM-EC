# ml-concept-visualizer

> Brief: Overview and index of ML visualization files in this repository.

## By Arash Saifhashemi

Interactive visualizations for machine learning, deep learning, and performance-engineering concepts used in lectures.

## Folder Structure

- **fundamentals/**  
  Core concepts and activation/probability intuition.
- **classical-ml-classification/**  
  Classification algorithms and decision boundaries.
- **cnn-architectures/**  
  Convolution operations, bottlenecks, pooling, and ResNet ideas.
- **cache-optimization/**  
  Cache hierarchy and memory behavior concepts.
- **gemm-optimization/**  
  GEMM, tiling, loop ordering, and cache-miss derivations.
- **kernel-optimization/**  
  Spatial/temporal reuse and kernel-level optimization ideas.
- **dataflow-loop-nests/**  
  Loop-nest and dataflow strategies (e.g., weight-stationary).
- **performance-modeling/**  
  Performance models such as roofline.

## Naming Convention

Files use **kebab-case** and descriptive names, for example:

- `softmax-function-visualizer.html`
- `convolution-layer-tensor-computation.html`
- `gemm-nested-loops-baseline.html`

## Notes

- Most files are standalone HTML visualizations.
- Open any `.html` file directly in a browser.
- Keep new files in the most relevant topic folder and follow kebab-case naming.
