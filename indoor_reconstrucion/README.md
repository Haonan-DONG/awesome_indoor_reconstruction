# Indoor Reconstruction Pipeline.

## Data Generator
### Aim
1. Point cloud to depth, using the faro as an example.

### Data
- [ ] [ETH3D](https://github.com/ETH3D/dataset-pipeline)
- [x] 202 frame abstraction.

### Note
1. clean up the scan point cloud.
2. move the scan cube map and images into the same directory.
3. get a finer mesh.

## Mesh
- [x] [Poisson Reconstruction](https://www.cs.jhu.edu/~misha/Code/PoissonRecon/Version13.8/)


## Neural Radiance Field
1. Neural Recon with our custom data.
- [X] Key frame extraction.
- [X] Align to the Scannet.
- [X] Intrinsic checking and the resolution.
- [X] Pose checking.
- [ ] Scene generalization with scannet.
- [ ] Pose Expanding for mathematics.