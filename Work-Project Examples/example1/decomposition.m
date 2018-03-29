function decomp=decomposition(im12, N, dirname, name)
sigma = 2;
dirname =  sprintf('./%s',dirname);
mkdir(dirname);
decomp = [];
for i = 1:N
%     fil = fspecial('gaussian', sigma, 5);
%     imblur = imfilter(im12, fil);
    imblur = imgaussfilt(im12,sigma);
    im = im12 - imblur;
    file_name = sprintf('./%s/%s_sigma_%d.jpg',dirname, name, sigma);
    if i == N
        imwrite(imblur, file_name);
    else
        imwrite(im+0.5, file_name);
    end   
    sigma = sigma .* 2;
    im12 = imblur;
end
