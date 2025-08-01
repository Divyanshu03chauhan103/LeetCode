SELECT 
    DISTINCT PRODUCT_ID,
    IF(
        (
            SELECT NEW_PRICE
            FROM PRODUCTS P2
            WHERE P2.PRODUCT_ID = P1.PRODUCT_ID
              AND P2.CHANGE_DATE <= '2019-08-16'
            ORDER BY CHANGE_DATE DESC
            LIMIT 1
        ) IS NULL,
        10,
        (
            SELECT NEW_PRICE
            FROM PRODUCTS P2
            WHERE P2.PRODUCT_ID = P1.PRODUCT_ID
              AND P2.CHANGE_DATE <= '2019-08-16'
            ORDER BY CHANGE_DATE DESC
            LIMIT 1
        )
    ) AS PRICE
FROM PRODUCTS P1;
