%% mixed and match
nom = 'mix';
file1 = sprintf('%s.jpg', nom);
file2 = sprintf('%s_2.jpg', nom);
filemask = sprintf('%s_mask.jpg', nom);

inverse = false;
if inverse
    filetemp = file1;
    file1 = file2;
    file2 = filetemp;
end   

im1 = im2double(imread(file1));
im2 = im2double(imread(file2));
mask = im2double(imread(filemask));

[h, ~, ~] = size(im1);
disp(h); %just to be sure I have the same size

im1 = imresize(im1, [h NaN]);
im2 = imresize(im2, [h NaN]);
mask = imresize(mask, [h NaN]);
mask = rgb2gray(mask);

dirname = nom;
image = melange(im1, im2, mask, 10, dirname);

fileresult = sprintf('%s_result.jpg', nom);
imshow(image);
imwrite(image, fileresult);





