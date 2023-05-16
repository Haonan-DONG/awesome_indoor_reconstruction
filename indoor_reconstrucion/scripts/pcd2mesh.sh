# # input $1 the path.
mkdir -p $1/surface_reconstruction
# generate the normal
echo "Start to calculate the normal."
../DataGenerator/PointCloud2Depth/build/NormalEstimator -i $1/scan_clean/scan_alignment.mlp -o $1/surface_reconstruction/point_cloud_with_normals.ply --neighbor_count 8
echo "Start to Possion Reconstruction."
../PoissonReconstruction/Bin/Linux/PoissonRecon --in $1/surface_reconstruction/point_cloud_with_normals.ply --out $1/surface_reconstruction/surface.ply --depth 10 --colors --data 16 --density