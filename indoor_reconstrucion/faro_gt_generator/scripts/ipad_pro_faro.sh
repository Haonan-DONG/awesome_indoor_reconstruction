colmap feature_extractor --database_path data.db --image_path cube_maps --ImageReader.camera_params 1024,1024,1024 --ImageReader.camera_model SIMPLE_PINHOLE --ImageReader.single_camera 1
colmap feature_extractor --database_path data.db --image_path images/ --ImageReader.camera_params 1566.254760,954.734619,716.97369,0.000001 --ImageReader.single_camera 1
colmap exhaustive_matcher --database_path data.db
colmap mapper --database_path data.db --image_path . --output_path .
SfMScaleEstimator -s sparse_reconstruction -si . -i scan_clean -o sparse_reconstruction_scaled --cube_map_face_camera_id 1
mkdir surface_reconstruction
ICPScanAligner -i sparse_reconstruction_scaled/meshlab_project.mlp -o scan_clean/scan_alignment.mlp -d 0.01 --max_iterations 100 --convergence_threshold 1e-10 --number_of_scales 4
NormalEstimator -i scan_clean/scan_alignment.mlp -o surface_reconstruction/point_cloud_with_normals.ply --neighbor_count 8

mkdir multi_res_point_cloud_cache