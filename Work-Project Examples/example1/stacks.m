function stacks(im12, N, dirname, name)
sigma = 2;
dirname =  sprintf('./%s',dirname);
mkdir(dirname);
for i = 1:N
%     fil = fspecial('gaussian', sigma, 5);
%     im = imfilter(im12, fil);
    im = imgaussfilt(im12, sigma);
    file_name = sprintf('./%s/%s_sigma_%d.jpg',dirname, name, sigma);
    imwrite(im, file_name);
    sigma = sigma .* 2;
end