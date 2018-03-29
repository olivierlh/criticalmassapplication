function imfinal=melange(im1,im2,mask, N, dirname)

mask = im2double(mask);

decomposition(im1, N, dirname, 'im');
decomposition(im2, N, dirname, 'im2');
stacks(mask, N, dirname, 'mask');
sigma = 2;
for i = 1:N
    dirname =  sprintf('./%s',dirname);
    file_name = sprintf('./%s/%s_sigma_%d.jpg',dirname, 'im', sigma);
    file_name2 = sprintf('./%s/%s_sigma_%d.jpg',dirname, 'im2', sigma);
    mask2name = sprintf('./%s/%s_sigma_%d.jpg',dirname, 'mask', sigma);
    im3 = im2double(imread(file_name));
    im4 = im2double(imread(file_name2));
    mask2 = im2double(imread(mask2name));
    
    im3 = im3 .* repmat(mask2, [1,1,3]);
    mask2inverse = mask2;
    
    for idx = 1:numel(mask2)
        mask2inverse(idx) = 1 - mask2(idx);
    end
    
    im4 = im4 .* repmat(mask2inverse, [1,1,3]);
    
    melange = im3 + im4;
    melangeName = sprintf('./%s/%s_sigma_%d.jpg',dirname, 'melange', sigma);
    imwrite(melange, melangeName)
    sigma = sigma .* 2;
end
sigma = 2;
imfinal = [];
for i = 1:N 
    melangeName = sprintf('./%s/%s_sigma_%d.jpg',dirname, 'melange', sigma);
    im = im2double(imread(melangeName));
    if isempty(imfinal)
        imfinal = im-0.5;
    else
        if i == N
            imfinal = imfinal + im;
        else
            imfinal = imfinal + im-0.5;
        end
    end
    sigma = sigma .* 2;
end
