# Indoor Reconstruction Pipeline.

## Using Faro to build up a database-generator pipeline.

### 1. rgb-d Pipeline
- [ ] rgb camera calibration.
- [ ] rgb sequence encounter.
- [ ] depth completion.
- [ ] low depth optimization (mvs / nerf)
- [ ] geometric propagation.
- [ ] precision evaluation (GT). with downscale the depth.
1. tof and high-res depth with mask
2. mesh
3. pose evaluation

### 2. pipeline
- [ ] [ETH3D](https://github.com/ETH3D/dataset-pipeline)
- [x] [COLMAP](https://github.com/colmap/colmap)
- [x] [Poisson Reconstruction](https://www.cs.jhu.edu/~misha/Code/PoissonRecon/Version13.8/)

### 3. dataset.
- [x] 202 frame abstraction.
- [x] other's processing.
- [ ] multi-point cloud dataset

### Note
1. clean up the scan point cloud.
2. move the scan cube map and images into the same directory.
3. get a finer mesh.

## Using other tof machines.